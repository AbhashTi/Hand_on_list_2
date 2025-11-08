/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : . Write a separate program using signal system call to catch the following signals.
e. SIGVTALRM
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM from setitimer()!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handler);

    timer.it_value.tv_sec = 3;  // Initial expiration
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 3; // Interval
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while(1) {
        pause(); // Wait for signals
    }

    return 0;
}
/*
  OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans8e.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans8e.c -o ans8e.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans8e.out
Caught SIGALRM from setitimer()!
Caught SIGALRM from setitimer()!
^C
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 
 */
