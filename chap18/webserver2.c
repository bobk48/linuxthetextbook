#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <systemd/sd-journal.h>
#define VERSION 5
#define BUFSIZE 8096
#define ERROR      42
#define LOG        44
#define FORBIDDEN 403
#define NOTFOUND  404

struct {
	char *ext;
	char *filetype;
} extensions [] = {
	{"gif", "image/gif" },  
	{"jpg", "image/jpg" }, 
	{"jpeg","image/jpeg"},
	{"png", "image/png" },  
	{"ico", "image/ico" },  
	{"zip", "image/zip" },  
	{"gz",  "image/gz"  },  
	{"tar", "image/tar" },  
	{"htm", "text/html" },  
	{"html","text/html" },  
	{0,0} };

void journal(int type, char *s1, char *s2, int socket_fd)
{
	int fd ;
	char logbuffer[BUFSIZE*2];

	switch (type) {
        case ERROR: sd_journal_print(LOG_NOTICE, "ERROR: %s:%s Errno=%d exiting pid=%d",s1, s2, errno,getpid());
		break;
	case FORBIDDEN: 
		(void)write(socket_fd, "HTTP/1.1 403 Forbidden\nContent-Length: 185\nConnection: close\nContent-Type: text/html\n\n<html><head>\n<title>403 Forbidden</title>\n</head><body>\n<h1>Forbidden</h1>\nThe requested URL, file type or operation is not allowed on this simple static file webserver.\n</body></html>\n",271);
                sd_journal_print(LOG_NOTICE, "FORBIDDEN: %s:%s",s1, s2);
		break;
	case NOTFOUND: 
		(void)write(socket_fd, "HTTP/1.1 404 Not Found\nContent-Length: 136\nConnection: close\nContent-Type: text/html\n\n<html><head>\n<title>404 Not Found</title>\n</head><body>\n<h1>Not Found</h1>\nThe requested URL was not found on this server.\n</body></html>\n",224);
		
                sd_journal_print(LOG_NOTICE, "NOT FOUND: %s:%s",s1, s2);
		break;
        case LOG: sd_journal_print(LOG_NOTICE, "INFO: %s:%s:%d",s1, s2,socket_fd);
                break;
	}	
	if(type == ERROR || type == NOTFOUND || type == FORBIDDEN) exit(3);
}

void web(int fd, int hit)
{
	int j, file_fd, buflen;
	long i, ret, len;
	char * fstr;
	static char buffer[BUFSIZE+1];

	ret =read(fd,buffer,BUFSIZE);
	if(ret == 0 || ret == -1) {
		journal(FORBIDDEN,"failed to read browser request","",fd);
	}
	if(ret > 0 && ret < BUFSIZE)	
		buffer[ret]=0;
	else buffer[0]=0;
	for(i=0;i<ret;i++)
		if(buffer[i] == '\r' || buffer[i] == '\n')
			buffer[i]='*';
	journal(LOG,"request",buffer,hit);
	if( strncmp(buffer,"GET ",4) && strncmp(buffer,"get ",4) ) {
		journal(FORBIDDEN,"Only simple GET operation supported",buffer,fd);
	}
	for(i=4;i<BUFSIZE;i++) { 
		if(buffer[i] == ' ') { 
			buffer[i] = 0;
			break;
		}
	}
	for(j=0;j<i-1;j++) 
		if(buffer[j] == '.' && buffer[j+1] == '.') {
			journal(FORBIDDEN,"Parent directory (..) path names not supported",buffer,fd);
		}
	if( !strncmp(&buffer[0],"GET /\0",6) || !strncmp(&buffer[0],"get /\0",6) ) 
		(void)strcpy(buffer,"GET /index.html");

	buflen=strlen(buffer);
	fstr = (char *)0;
	for(i=0;extensions[i].ext != 0;i++) {
		len = strlen(extensions[i].ext);
		if( !strncmp(&buffer[buflen-len], extensions[i].ext, len)) {
			fstr =extensions[i].filetype;
			break;
		}
	}
	if(fstr == 0) journal(FORBIDDEN,"file extension type not supported",buffer,fd);

	if(( file_fd = open(&buffer[5],O_RDONLY)) == -1) {  
		journal(NOTFOUND, "failed to open file",&buffer[5],fd);
	}
	journal(LOG,"SEND",&buffer[5],hit);
	len = (long)lseek(file_fd, (off_t)0, SEEK_END); 
	      (void)lseek(file_fd, (off_t)0, SEEK_SET); 
          (void)sprintf(buffer,"HTTP/1.1 200 OK\nServer: webserver2/%d.0\nContent-Length: %ld\nConnection: close\nContent-Type: %s\n\n", VERSION, len, fstr); 
	journal(LOG,"Header",buffer,hit);
	(void)write(fd,buffer,strlen(buffer));

	
	while (	(ret = read(file_fd, buffer, BUFSIZE)) > 0 ) {
		(void)write(fd,buffer,ret);
	}
	sleep(1);	
	close(fd);
	exit(1);
}

int main(int argc, char **argv)
{
	int i, port, pid, listenfd, socketfd, hit;
	socklen_t length;
	static struct sockaddr_in cli_addr; 
	static struct sockaddr_in serv_addr; 

	
	if(fork() != 0)
		return 0; 
	(void)signal(SIGCHLD, SIG_IGN); 
	(void)signal(SIGHUP, SIG_IGN); 
	for(i=0;i<32;i++)
		(void)close(i);		
	(void)setsid();		
	journal(LOG,"webserver2 starting",argv[1],getpid());
	
	if((listenfd = socket(AF_INET, SOCK_STREAM,0)) <0)
		journal(ERROR, "system call","socket",0);
	port = atoi(argv[1]);
	if(port < 0 || port >60000)
		journal(ERROR,"Invalid port number (try 1->60000)",argv[1],0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);
	if(bind(listenfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) <0)
		journal(ERROR,"system call","bind",0);
	if( listen(listenfd,64) <0)
		journal(ERROR,"system call","listen",0);
	for(hit=1; ;hit++) {
		length = sizeof(cli_addr);
		if((socketfd = accept(listenfd, (struct sockaddr *)&cli_addr, &length)) < 0)
			journal(ERROR,"system call","accept",0);
		if((pid = fork()) < 0) {
			journal(ERROR,"system call","fork",0);
		}
		else {
			if(pid == 0) { 	
				(void)close(listenfd);
				web(socketfd,hit); 
			} else { 	
				(void)close(socketfd);
			}
		}
	}
}
