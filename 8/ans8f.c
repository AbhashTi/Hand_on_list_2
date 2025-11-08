/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : . Write a separate program using signal system call to catch the following signals.
f.SIGVTALRM
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGVTALRM!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, handler);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while(1) {
        for (volatile int i = 0; i < 1000000; i++); // Consume CPU
    }

    return 0;
}
/*
  OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans8f.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans8f.c -o ans8f.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans8f.out
Caught SIGVTALRM!
Caught SIGVTALRM!
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */
