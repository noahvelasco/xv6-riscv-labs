# Lab Report 1 - Noah Velasco

## Task 1 - Explore and Report 3 Additional Commands

### echo

The echo command is meant to take an additional argument and use the "write" system call to write to File Descriptor 1
which is the standard output (stdout) to the command line. Below is an example run 

```
$ echo hello world
hello world
```

### kill
The kill command is meant to end exit a particular process. The command takes a number (int) that indicates a process identifier or PID. The "exit" system call is used to exit the indicated process @ PID. Below is an example run. 

```
1 sleep init // from Ctrl + p
2 sleep init // from Ctrl + p

$ kill 2
init: starting sh

1 sleep init // from Ctrl + p
9 sleep sh // from Ctrl + p
```
As you can see the sh has a new PID since the kill command used the system call exit to stop the sh process with PID=2

### rm 
The rm command is used to removed directories using the "unlink" system call. The "unlink" system call is used to delete a name and the file it refers to from the file system. Below is an example run. 

```
$ ls
.              1 1 1024
..             1 1 1024
README         2 2 2226
cat            2 3 23976
echo           2 4 22800
forktest       2 5 13152
grep           2 6 27328
init           2 7 23896
kill           2 8 22752
ln             2 9 22704
ls             2 10 26208
mkdir          2 11 22864
rm             2 12 22848
sh             2 13 41736
stressfs       2 14 23864
usertests      2 15 156080
grind          2 16 38040
wc             2 17 25104
zombie         2 18 22256
console        3 19 0
$ mkdir test
$ ls
.              1 1 1024
..             1 1 1024
README         2 2 2226
cat            2 3 23976
echo           2 4 22800
forktest       2 5 13152
grep           2 6 27328
init           2 7 23896
kill           2 8 22752
ln             2 9 22704
ls             2 10 26208
mkdir          2 11 22864
rm             2 12 22848
sh             2 13 41736
stressfs       2 14 23864
usertests      2 15 156080
grind          2 16 38040
wc             2 17 25104
zombie         2 18 22256
console        3 19 0
test           1 20 32
$ rm test
$ ls
.              1 1 1024
..             1 1 1024
README         2 2 2226
cat            2 3 23976
echo           2 4 22800
forktest       2 5 13152
grep           2 6 27328
init           2 7 23896
kill           2 8 22752
ln             2 9 22704
ls             2 10 26208
mkdir          2 11 22864
rm             2 12 22848
sh             2 13 41736
stressfs       2 14 23864
usertests      2 15 156080
grind          2 16 38040
wc             2 17 25104
zombie         2 18 22256
console        3 19 0
```
As you can see, "test" is no longer here since the file was unlinked and thus deleted. 

---

## Task 2 - Implement the Sleep Utility

The goal of this task was to get the xv6 OS to run a command "sleep <time>" and pause for a user-specified number of ticks. A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip.


To solve this problem I followed the lab instructions - 

1. Use other files as a baseline for getting input
2. Print an error if there is not 2 arguements.
3. Use the system call sleep (looked at kernel/sysproc.c and user.h)
4. Exit in the main to exit program
5. Added "sleep" to UPROGS in the makefile

This task was fairly simple - it was very similar to user/kill.c. The program takes an additional arguement indicating the amount of clock ticks the system will sleep (pause) for. What's really happening is that the kernel is acquiring a lock on the sh and releasing the lock after the specified amount of ticks have past. Below is a sample run

```
$ sleep    
usage: sleeps but needs more args...
$ sleep 1000 //sleeps for 1000 ticks
$
```



