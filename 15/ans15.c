/*
============================================================================
Name : ans15.c
Author : Abhash Tiwari
Description :Write a simple program to send some data from parent to the child process.  
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; // fd[0] = read end, fd[1] = write end
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    // Fork child process
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process
        close(fd[0]); // Close unused read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        printf("Parent sent: %s\n", write_msg);
        close(fd[1]); // Close write end after writing
    } else {
        // Child process
        close(fd[1]); // Close unused write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]); // Close read end
    }

    return 0;
}
/*
  OUTPUT::

  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans15.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans15.c -o ans15.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans15.out
Parent sent: Hello from parent!
Child received: Hello from parent!
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
