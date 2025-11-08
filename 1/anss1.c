/*
============================================================================
Name : ans1.c
Author : Abhash Tiwari
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
Date: 28th sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void handler(int signum) {
    printf("ITIMER_REAL: Timer expired!\n");
}

int main() {
    struct itimerval timer;

    // Install handler
    signal(SIGALRM, handler);

    // Initial expiration = 10s + 10µs
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    // Interval for periodic timer = 10s + 10µs
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    // Set the timer
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    // Keep running
    while (1) {
        pause(); // wait for signal
    }

    return 0;
}

