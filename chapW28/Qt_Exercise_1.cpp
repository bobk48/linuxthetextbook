// helloLinux/main.cpp
#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
          QApplication a(argc, argv);
          QLabel label("Hello Linux");
           label.show();
           return a.exec();
}
