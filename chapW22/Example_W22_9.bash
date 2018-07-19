#!/bin/bash
# A time stamp variable for logging
TIMESTAMP=`date +%Y%m%d.%H%M`
# Destination directory location on the mirrored pair as a variable
DEST_DIR="/media/bob/Sony_16SA1"
# Source directory as a variable
SRC_DIR="/home/bob/nweb23"
# Variable for the backup file name file
FNAME="MyBackup"
# Variable for a log file, in an already created sub-directory in your home 
# directory, and name the log file with the file name and time stamp
LOG="/home/bob/log/$FNAME-$TIMESTAMP.log"
# Message that the backup is started
echo -e "Starting backup of $SRC_DIR directory" >> ${LOG}
# Compress the source directory and files, copy the tar.gz file to 
# your destination directory
tar -vczf ${DEST_DIR}/${FNAME}-${TIMESTAMP}.tar.gz ${SRC_DIR} >> ${LOG}
# Message that the backup has ended, and append to log file
echo -e "Ending backup of $SRC_DIR" >> ${LOG}
