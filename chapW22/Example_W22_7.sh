#!/bin/sh
# This assigns a local filesystem as the source to be transmitted
pool="/sender/send_dir"
# This assigns a remote destination 
destination="/mnt/receive"
# This names the IP address of the remote target host
host="192.168.0.8"
# Sets the date format for today 
today=`date +"%Y-%m-%d"`
# This sets the date format for yesterday 
yesterday=`date +"%Y-%m-%d" -d"-1 day"`
# Create today’s snapshot
snapshot_today="$pool@$today"
# look for a snapshot with this name, and if none exists, take the snapshot
if zfs list -H -o name -t snapshot | sort | grep "$snapshot_today$" > /dev/null 
     then
          echo " snapshot, $snapshot_today, already exists"
          exit 1
     else
          echo " taking todays snapshot, $snapshot_today"
          zfs snapshot -r $snapshot_today
fi
# look for yesterdays snapshot
snapshot_yesterday="$pool@$yesterday"
# If it exists, zfs send todays snapshot
if zfs list -H -o name -t snapshot | sort | grep "$snapshot_yesterday$" > /dev/null 
     then
          echo " yesterday snapshot, $snapshot_yesterday, exists, send todays backup"
          zfs send -R -i $snapshot_yesterday $snapshot_today | ssh root@$host 
                   zfs  receive –Fduv $destination
          echo " backup complete destroying yesterdays snapshot"
          zfs destroy -r $snapshot_yesterday
          exit 0
     else
          echo " missing yesterday snapshot aborting, $snapshot_yesterday"
          exit 1
fi
