/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child: will run 'ls -l'
        close(fd[0]); // Close read end

        // Redirect stdout to write end of pipe
        int old_stdout = dup(1);  // Save original stdout
        close(1);
        dup(fd[1]);
        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    } else {
        // Parent: will run 'wc'
        close(fd[1]); // Close write end

        // Redirect stdin to read end of pipe
        int old_stdin = dup(0); // Save original stdin
        close(0);
        dup(fd[0]);
        close(fd[0]);

        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }

    return 0;
}
/*
   	output::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans17a.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans17a.c -o ans17a.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans17a.out
     79     708    4582
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 
 */
