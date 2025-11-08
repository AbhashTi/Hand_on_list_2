/*
============================================================================
Name : ans1.c
Author : Abhash Tiwari
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
b. ITIMER_VIRTUAL
Date: 28th sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handler(int signum) {
    printf("ITIMER_VIRTUAL: Timer expired!\n");
}

int main() {
    struct itimerval timer;

    // Install handler
    signal(SIGVTALRM, handler);

    // Initial expiration = 10s + 10µs
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    // Interval = 10s + 10µs
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    // Set the timer
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    // Keep consuming CPU to trigger virtual timer
    while (1) {
        // busy work to consume CPU
    }

    return 0;
}

/*  OUTPUT::
 saurabh@abhash-HP-Laptop-14s-er0xxx:~$ vim anss2b.c
saurabh@abhash-HP-Laptop-14s-er0xxx:~$ gcc anss2b.c -o anss2b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./anss2b.out
ITIMER_VIRTUAL: Timer expired!
ITIMER_VIRTUAL: Timer expired!
^C
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 


 */
