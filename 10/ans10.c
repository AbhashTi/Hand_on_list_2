/*
============================================================================
Name : ans10.c
Author : Abhash Tiwari
Description :  Write a separate program using sigaction system call to catch the following signals.
b.SIGINT
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig, siginfo_t *info, void *ucontext) {
    printf("Caught SIGSEGV! Fault address: %p\n", info->si_addr);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;       // Use siginfo_t
    sa.sa_sigaction = handler;      // Handler function
    sigemptyset(&sa.sa_mask);

    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 42; // Cause segmentation fault

    return 0;
}
/*
  OUTPUT:: 
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans10.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans10.c -o ans10.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans10.out
Caught SIGSEGV! Fault address: (nil)
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
