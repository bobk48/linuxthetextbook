Welcome to the Github site of Linux: The Textbook, 2nd edition!

Starting in September of 2018, you will find all long program source code, 
weblinks, advisory information, and errata here. 
These elements will be found in their own files, for your examination and use.
The weblinks for the book are now available, and
in addition, the URL of the CRC website containing the supplementary
material described in the Preface is -

https://www.crcpress.com/9781138710085

Advisory information will be updated regularly,appearing on this README page, and will give
important changes in our representative Linux systems since the printing of the book.

We have added all program source code in Linux-compatible text format.

If you follow the instructions in the book Preface you will be able 
to "pull" everything from this Github site to a git-enabled directory on your own computer! 
Alternatively, you can just download the above-provided materials via a web
browser interface.

You can also report any errors you find in the printed book here.
Just email bobk48@gmail.com, and we will evaluate your error reports
or any other requests you make, and take appropriate action.

Have fun, and keep playing!

Advisory 2- We have now made advisory documents available in a folder. Our first installation into that folder is a .docx file that details how to install LXD on a CentOS 7.5 system with a ZFS backing store, and also how to give subsequently-created LXD containers a macvlan interface, so that they have an IP address in the same sub-net as the host automatically assigned to them by a DHCP server on your LAN. Check it out if you're a CentOS user!

Advisory 1- The Caveat shown in Chapter W23, Section 2.1 is no longer true! Thanks to the efforts of the developer of LXD, Stephane Graber, instructions for installing LXD on CentOS 7.5 1804 (core) are available at the following URL-

https://discuss.linuxcontainers.org/t/lxd-on-centos-7/1250/5

Follow these and you can then proceed to use CentOS 7.5 to accomplish what is shown in Chapter W23 on virtualization in Linux. The instructions also include installation of ZFS on CentOS 7.5, and allow integration of ZFS with your LXD containers. Of course, that integration is covered in Chapter W23 for Debian-family systems, and you will have to adapt what is shown there for CentOS.


Last revised 10/11/2018
