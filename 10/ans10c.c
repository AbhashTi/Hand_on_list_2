/*
============================================================================
Name : ans10.c
Author : Abhash Tiwari
Description :  Write a separate program using sigaction system call to catch the following signals.
c.SIGINT
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig, siginfo_t *info, void *ucontext) {
    printf("Caught SIGINT! Press Ctrl+C again to exit.\n");
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);

    while(1) {
        printf("Running... Press Ctrl+C\n");
        sleep(2);
    }

    return 0;
}
/*
   OUTPUT::
   
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans10c.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans10c.c -o ans10c.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans10c.out
Running... Press Ctrl+C
Running... Press Ctrl+C
Running... Press Ctrl+C
^CCaught SIGINT! Press Ctrl+C again to exit.
Running... Press Ctrl+C
^\Quit (core dumped)
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */

