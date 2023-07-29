Welcome to the GitHub site of Linux: The Textbook, 2nd edition!

Here you will find all long program source code, 
advisory information, errata, and weblinks.

The contents of the folders and files in this repository are as follows:

ICE - In-Chapter Exercise solutions for Chapters 1-18.

advisories - Documents related to the advisories.

Long C, Python, etc. program source code for the printed book chapters.

Errata.docx - Errata found or reported by the Last revised date.

README.md - This readme page contents.

Long C, Python, etc. program source code for the printed book chapters.

weblinks.docx - Weblinks for all chapters.

Plus, I just added back the W Chapters on Advanced System Proramming and TC shell scripting as
Chap_W20,21,29, & 30.

The folders contain elements in either sub-folders, or in individual files, for your examination, 
use, and download.

The newly revised URL of the CRC website containing the supplementary
material described in the Preface of the printed book is -

https://www.routledge.com/Linux-The-Textbook-Second-Edition/Sarwar-Koretsky/p/book/9780367571061

Advisory information will be updated regularly, appearing on this README page in numerical order
from bottom to top, oldest to most recent, giving important news about issues related to
the content of this repository, and also keeping you up to date on
important changes to our representative Linux systems since the printing of the book.

If you follow the instructions in the printed book Preface, you will be able 
to "pull" everything from this GitHub site to a git-enabled directory on your own computer! 
Alternatively, you can just download the above-provided materials via a web
browser interface.

Mansoor and I would greatly appreciate if you would also report any errors you find in the printed book here.
Just email bobk48@gmail.com, and we will evaluate your error reports,
or any other requests you make, and take appropriate action.

Have fun, and keep playing!

---------------------------

Advisory 20- I've deleted all of the W Chapters, in anticipation of posting them in the new repo
 RaspberryPiOS, in a more edited, and error-corrrected form. Keep your eye on that repo, and as
soon as the first volume of the new book is published by CRC/T&F, the W Chapters will begin to
magically reappear, in more finished, complete, and Raspberry Pi format!

Advisory 19- We have added an updated version of the weblinks file, weblinks.docx, which now contains
hyperlinks to resources for password cracking techniques, and other relevant password info, from
Chapter 5 in the printed book.

Advisory 18- If you're interested in setting up mdadm on your Linux installation, the following link
is a great supplement to Section 4.7.1 in Chapter W26. It provides you with up-to-date advisories about
mdadm installation and maintenance:

https://www.tecmint.com/create-raid1-in-linux/comment-page-5/#comment-1443154

Can you answer the question posed in the comment?

Advisory 17- Here's a great link to a book on creating GUI's with Python:

https://magazines-attachments.raspberrypi.org/books/full_pdfs/000/000/037/original/000_guizero_DIGITAL.pdf?1603705698

It's a great supplement to both our presentations of Python in Chapter W19, and GUI development
in Chapter W28.

Advisory 16- In Chapter W23, Section W23.2.2, Step 3, the lxc command that
allows you to "see all of the unofficial images ..." should be as follows:

$ sudo lxc image list images:

we advise testing all of the lxc/lxd instructions and examples shown in
that chapter in the latest version of Debian-family systems, such as
Linux Mint 20 and Ubuntu 20.04.

Advisory 15- In the supplementary chapter W23, in Example W23.9, Requirements Step 1., make sure in the command 
VBoxManage modifyvm "VMname" --natnet1 "192.168/16", you precede the command argument natnet with two(2) hyphen
characters. When we tested this Example on Linux Mint 20, with an Ubuntu 20.04 virtual machine in VirtualBox,
we used the equivalent command VBoxManage modifyvm "VMname" --nat-network1 "192.168/16" and it worked just as
well. No need for double quotes around VMname, but double quotes around the option argument 192.168/16 worked.

Advisory 14- We've added all of the W Chapters here for your reference.

Advisory 13- The newly revised link to the CRC website containing the supplementary 
materials specified in the Preface to the printed book has been changed to-

https://www.routledge.com/Linux-The-Textbook-Second-Edition/Sarwar-Koretsky/p/book/9780367571061 

As of 8/17/2020, this website does not contain all of the items designated in the Preface!
But, when all of them become available, we will issue a new advisory letting you know.
For now, you can use the ICE folder above to get the In-Chapter Exercise solutions. 

Advisory 12- To supplement the package management commands shown in the printed book, Appendix A,
which describe the apt-get command, it would be very worthwhile for you to use the Aptitude package
manager, described more fully at https://www.debian.org/doc/manuals/aptitude/index.en.html
This package manager has a text-based menu system that can be very usefully used to update the
packages installed on your Debian system. 

Advisory 11- The In-Chapter Exercise and End-of-Chapter Problem Solutions supplements specified in the Preface are now available at the CRC website for the book mentioned above.

Advisory 10- We added the remaining In-Chapter Exercise solutions for Chapters 1-18, so that you can now download them from here.

Advisory 9 *Edited 7/10/2019- Within the next few days, the In-Chapter Exercise and End-of-Chapter Problem Solutions supplements for the book, which we describe in the Preface, will be completed, and uploaded for use on both the Student and Instructor portions of the CRC website for the book mentioned above. These supplements will greatly enhance the usability of the book, for both teachers, and individual student learners. We will post a new advisory on the date that these resources become available on the book website, to inform you as such.

Advisory 8- Just a note about Linux distros, we have found that it is easier for a beginner to work with "downstream" distros (like Linux Mint or CentOS) rather than "upstream" ones (like Debian or Fedora). You can kinda see this reflected in Appendix A Installation Instructions in the printed book, where the upstream distros have way more complicated instructions for installing things, such as ZFS, if they have them at all!

Advisory 7- A good example of a progressive, forward looking Linux distro running Wayland is Fedora 29 Desktop, with Gnome as the default desktop environment. Once you have installed Fedora 29 Desktop on your computer, the following commands issued in a terminal show that Wayland is indeed the display system being used:

$ loginctl

SESSION  UID USER SEAT  TTY 

      2 1000 bob  seat0 tty2

$ loginctl show-session 2 -p Type

Type=wayland

$

Advisory 6- There's a great, and very useful for beginners Integrated Development Environment (IDE) for Python 3 on Linux, named "Thonny". If you are just starting out in Python, and have not looked at Chapter W19 yet, you can download Thonny on a Linux Mint 19 system with the following command-

sudo apt-get install thonny

Then, with the extensive documentation available with that system, you can run through everything shown in our Chapter W19, and use Thonny! Or, if you have gone through all of Chapter W19, you can use Thonny to redo the examples and problems presented there, and see how an IDE expedites your use of Python.

Advisory 5- We have added an example to the advisories folder of how to share a ZFS zpool on a server with a client on the same network, using the Network File System(NFS). This example bridges the gap between our presentation of ZFS, and a typical modern topic in Linux, NFS.

Advisory 4- We have added generic instructions for how to fork and sync the contents of a GitHub repo, and placed these instructions in the advisories folder, in a file named forking.docx. You can experiment with these generic instructions, and then, as an alternative to "pulling" everything from this GitHub site for the book, as specified in the Preface, you can adapt the generic instructions to fork and keep your local copy of the book's Github repo up to date via syncing.

Advisory 3- For your convenience, we have added the In-Chapter Exercise Solutions for Chapters 2,3,17,18,W19,W22,W23,W24,W25,W26,W27,W28, and W29 in the folder ICE.
A complete set of these for all printed book chapters and W chapters will be available at the above listed CRC website for the book,
and when that complete set is available, we will post an advisory here.

Advisory 2- We have now made advisory documents available in a folder. Our first installation into that folder is a .docx file that details how to install LXD on a CentOS 7.5 system with a ZFS backing store, and also how to give subsequently-created LXD containers a macvlan interface, so that they have an IP address in the same sub-net as the host automatically assigned to them by a DHCP server on your LAN. Check it out if you're a CentOS user!

Advisory 1- The Caveat shown in Chapter W23, Section 2.1 is no longer true! Thanks to the efforts of the developer of LXD, Stephane Graber, instructions for installing LXD on CentOS 7.5 1804 (core) are available at the following URL-

https://discuss.linuxcontainers.org/t/lxd-on-centos-7/1250/5

Follow these and you can then proceed to use CentOS 7.5 to accomplish what is shown in Chapter W23 on virtualization in Linux. The instructions also include installation of ZFS on CentOS 7.5, and allow integration of ZFS with your LXD containers. Of course, that integration is covered in Chapter W23 for Debian-family systems, and you will have to adapt what is shown there for CentOS.


Last revised 7/29/2023
