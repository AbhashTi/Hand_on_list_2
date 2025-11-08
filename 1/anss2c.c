/*
============================================================================
Name : ans1.c
Author : Abhash Tiwari
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec andm 10micro second
c.ITIMER_PROF
Date: 28th sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handler(int signum) {
    printf("ITIMER_PROF: Timer expired!\n");
}

int main() {
    struct itimerval timer;

    // Install handler
    signal(SIGPROF, handler);

    // Initial expiration = 10s + 10µs
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    // Interval = 10s + 10µs
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    // Set the timer
    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    // Consume CPU (user + system)
    while (1) {
        // Busy work (user time)
        for (volatile int i = 0; i < 1000000; i++);
    }

    return 0;
}
/* OUTPUT::
 
saurabh@abhash-HP-Laptop-14s-er0xxx:~$ vim anss2c.c
saurabh@abhash-HP-Laptop-14s-er0xxx:~$ gcc anss2c.c -o anss2.out
saurabh@abhash-HP-Laptop-14s-er0xxx:~$ ./anss2c.out
bash: ./anss2c.out: No such file or directory
saurabh@abhash-HP-Laptop-14s-er0xxx:~$ ./anss2c.out
bash: ./anss2c.out: No such file or directory
saurabh@abhash-HP-Laptop-14s-er0xxx:~$ ./anss2.out
ITIMER_PROF: Timer expired!
ITIMER_PROF: Timer expired!
^C
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 


 */
