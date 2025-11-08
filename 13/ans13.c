/*
============================================================================
Name : ans13.c
Author : Abhash Tiwari
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    printf("PID of this process: %d\n", getpid());

    // Attempt to catch SIGSTOP
    signal(SIGSTOP, handler);  // WARNING: SIGSTOP cannot actually be caught

    printf("Waiting for SIGSTOP...\n");

    while(1) {
        sleep(1);
        printf("Still running...\n");
    }

    return 0;
}
/*
   OUTPUT::

  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans13.c 
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans13.c -o ans13.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans13.out
PID of this process: 13067
Waiting for SIGSTOP...
Still running...
Still running...
Still running...
^C
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ^C

 */
