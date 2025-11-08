
/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : . Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 28th Aug, 2025.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGSEGV!\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handler);

    int *p = NULL;
    *p = 42; // Causes segmentation fault

    return 0;
}

/*
   OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans8a.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans8a.c -o ans8a.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans8a.out
Caught SIGSEGV!
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
