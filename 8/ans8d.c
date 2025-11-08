/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : . Write a separate program using signal system call to catch the following signals.
d. SIGALRM
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM from alarm()!\n");
}

int main() {
    signal(SIGALRM, handler);

    printf("Setting alarm for 5 seconds...\n");
    alarm(5);

    pause(); // Wait for signal
    return 0;
}
/*
  OUTPUT::
  
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans8d.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans8d.c -o ans8d.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans8d.out
Setting alarm for 5 seconds...
Caught SIGALRM from alarm()!
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */
