/*
============================================================================
Name : ans13.c
Author : Abhash Tiwari
Description :Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not. 
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID to send SIGSTOP>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    printf("Sending SIGSTOP to PID %d\n", pid);

    if (kill(pid, SIGSTOP) == -1) {
        perror("kill failed");
        return 1;
    }

    printf("SIGSTOP sent.\n");
    return 0;
}
/*
   OUTPUT::

   saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans13b.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans13b.c -o ans13b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans13b.out
Usage: ./ans13b.out <PID to send SIGSTOP>
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ps -ef | grep ans13
saurabh    13602    5322  0 23:39 pts/0    00:00:00 grep --color=auto ans13
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ^C

 */
