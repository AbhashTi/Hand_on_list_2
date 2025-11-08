/*
============================================================================
Name : ans9.c
Author : Abhash Tiwari
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Step 1: Ignoring SIGINT (Ctrl+C will be ignored) for 5 seconds...\n");

    // Ignore SIGINT
    signal(SIGINT, SIG_IGN);

    for (int i = 5; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }

    printf("Step 2: Restoring default action for SIGINT (Ctrl+C will now terminate the program)...\n");

    // Restore default action
    signal(SIGINT, SIG_DFL);

    while(1) {
        printf("Running... Press Ctrl+C to exit.\n");
        sleep(2);
    }

    return 0;
}
/*
  OUTPUT::
  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans9.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans9.c -o ans9.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans9.out
Step 1: Ignoring SIGINT (Ctrl+C will be ignored) for 5 seconds...
5...
4...
3...
2...
1...
Step 2: Restoring default action for SIGINT (Ctrl+C will now terminate the program)...
Running... Press Ctrl+C to exit.
Running... Press Ctrl+C to exit.
^\Quit (core dumped)
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$


 */
