/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : . Write a separate program using signal system call to catch the following signals.
c.SIGALRM(use alarm system call)
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGFPE! Division by zero detected.\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handler);

    int a = 1, b = 0;
    int c = a / b; // Causes SIGFPE
    printf("Result: %d\n", c);

    return 0;
}

/*
 
   OUTPUT::

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans8c.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans8c.c -o ans8.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans8c.c
bash: ./ans8c.c: Permission denied
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans8c.out
Running... Press Ctrl+C
Running... Press Ctrl+C
^CCaught SIGINT 1 times
Running... Press Ctrl+C
^\Quit (core dumped)
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 


 */
