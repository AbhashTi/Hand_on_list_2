===========================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : . Write a separate program using signal system call to catch the following signals.
g.SIGPROF
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGPROF!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, handler);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while(1) {
        for (volatile int i = 0; i < 1000000; i++); // Consume CPU
    }

    return 0;
}

/*
   OUTPUT:: 
   
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans8g.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans8g.c -o ans8g.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans8g.out
Caught SIGPROF!
Caught SIGPROF!
^C
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */
