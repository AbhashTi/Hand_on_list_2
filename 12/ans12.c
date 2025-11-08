/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process
        printf("Parent process PID: %d\n", getpid());
        printf("Parent will sleep for 10 seconds...\n");
        sleep(10);  // Give child time to send SIGKILL
        printf("Parent exiting normally (if not killed by child)\n");
    } else {
        // Child process
        printf("Child process PID: %d\n", getpid());
        printf("Child sending SIGKILL to parent PID: %d\n", getppid());

        // Send SIGKILL to parent
        kill(getppid(), SIGKILL);

        // Sleep a bit to ensure parent is gone
        sleep(5);

        // Show new parent (should be 1 for init/systemd)
        printf("Child's new parent PID (orphaned): %d\n", getppid());
    }

    return 0;
}
/*
  OUTPUT::

  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans12.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans12.c -o ans12.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans12.out
Parent process PID: 12757
Parent will sleep for 10 seconds...
Child process PID: 12758
Child sending SIGKILL to parent PID: 12757
Killed
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ Child's new parent PID (orphaned): 2062

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */

