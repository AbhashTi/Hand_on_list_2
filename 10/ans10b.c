/*
============================================================================
Name : ans10.c
Author : Abhash Tiwari
Description :  Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
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
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans10b.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans10b.c -o ans10.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans10b.out
bash: ./ans10b.out: No such file or directory
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans10b.c -o ans10b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans10b.out
Running... Press Ctrl+C
Running... Press Ctrl+C
^CCaught SIGINT! Press Ctrl+C again to exit.
Running... Press Ctrl+C
Running... Press Ctrl+C
^CCaught SIGINT! Press Ctrl+C again to exit.
Running... Press Ctrl+C
^\Quit (core dumped)
saurabh@saurabh-HP-Laptop-14s-er0xxx:
 */
