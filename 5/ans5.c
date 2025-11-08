/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    long val;

    // a) Max length of arguments to exec()
    val = sysconf(_SC_ARG_MAX);
    if (val == -1)
        perror("ARG_MAX");
    else
        printf("a) Max length of arguments to exec() : %ld\n", val);

    // b) Max number of simultaneous processes per user ID
    val = sysconf(_SC_CHILD_MAX);
    if (val == -1)
        perror("CHILD_MAX");
    else
        printf("b) Max number of simultaneous processes per user ID : %ld\n", val);

    // c) Number of clock ticks (jiffies) per second
    val = sysconf(_SC_CLK_TCK);
    if (val == -1)
        perror("CLK_TCK");
    else
        printf("c) Clock ticks (jiffies) per second : %ld\n", val);

    // d) Max number of open files
    val = sysconf(_SC_OPEN_MAX);
    if (val == -1)
        perror("OPEN_MAX");
    else
        printf("d) Max number of open files : %ld\n", val);

    // e) Size of a page
    val = sysconf(_SC_PAGESIZE);
    if (val == -1)
        perror("PAGESIZE");
    else
        printf("e) Page size (bytes) : %ld\n", val);

    // f) Total number of pages in physical memory
    val = sysconf(_SC_PHYS_PAGES);
    if (val == -1)
        perror("PHYS_PAGES");
    else
        printf("f) Total number of pages in physical memory : %ld\n", val);

    // g) Number of currently available pages in physical memory
    val = sysconf(_SC_AVPHYS_PAGES);
    if (val == -1)
        perror("AVPHYS_PAGES");
    else
        printf("g) Available pages in physical memory : %ld\n", val);

    return 0;
}

/*
   OUTPUT::

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans5.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans5.c -o ans5.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans5.out
a) Max length of arguments to exec() : 2097152
b) Max number of simultaneous processes per user ID : 29896
c) Clock ticks (jiffies) per second : 100
d) Max number of open files : 1024
e) Page size (bytes) : 4096
f) Total number of pages in physical memory : 1953600
g) Available pages in physical memory : 438578
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
