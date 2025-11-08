/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : . Write a separate program using signal system call to catch the following signals.
b. SIGFPE
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT! Press Ctrl+C again to exit.\n");
}

int main() {
    signal(SIGINT, handler);

    while(1) {
        printf("Running... Press Ctrl+C\n");
        sleep(2);
    }

    return 0;
}

/*
  OUTPUT::

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans8b.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans8b.c -o ans8b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans8b.out
Running... Press Ctrl+C
Running... Press Ctrl+C
Running... Press Ctrl+C
^CCaught SIGINT! Press Ctrl+C again to exit.
Running... Press Ctrl+C
^\Quit (core dumped)
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
