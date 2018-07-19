#!/usr/bin/python3
import stat, sys, os, glob
try:
    #Getting search pattern from user and assigning it to a list
    pattern = input("Enter the file pattern to search for:\n")
    matching_Files = glob.glob(pattern)
    print ("Files:")
    print (matching_Files)
    print ("*******************************")
    for file in matching_Files:
        mode=stat.S_IMODE(os.lstat(file)[stat.ST_MODE])
        print ("\nPermissions for file ", file, ":")
        for level in "USR", "GRP", "OTH":
            for perm in "R", "W", "X":
                if mode & getattr(stat,"S_I"+perm+level):
                    print (level, " has ", perm, " permission")
                else:
                    print (level, " does NOT have ", perm, "permission")
except:
    print ("Error - check your input of file matching pattern")
