/*
============================================================================
Name : ans10.c
Author : Abhash Tiwari
Description :   Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa_ignore, sa_default;

    // Step 1: Ignore SIGINT
    sa_ignore.sa_handler = SIG_IGN;   // Ignore handler
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;

    if (sigaction(SIGINT, &sa_ignore, NULL) == -1) {
        perror("sigaction - ignore");
        exit(1);
    }

    printf("SIGINT is now ignored. Try pressing Ctrl+C (it won't terminate).\n");
    sleep(5);

    // Step 2: Reset to default action
    sa_default.sa_handler = SIG_DFL;  // Default handler
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;

    if (sigaction(SIGINT, &sa_default, NULL) == -1) {
        perror("sigaction - default");
        exit(1);
    }

    printf("SIGINT reset to default. Press Ctrl+C now (program will terminate).\n");

    // Wait for signal
    while (1) {
        pause();  // wait for any signal
    }

    return 0;
}
/*
   OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans11.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans11.c -o ans11.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans11.out
SIGINT is now ignored. Try pressing Ctrl+C (it won't terminate).
^CSIGINT reset to default. Press Ctrl+C now (program will terminate).
^C
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ^C
 */
