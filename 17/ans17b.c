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
        // Child: ls -l
        close(fd[0]);             // Close unused read end
        dup2(fd[1], 1);           // Redirect stdout to pipe write end
        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    } else {
        // Parent: wc
        close(fd[1]);             // Close unused write end
        dup2(fd[0], 0);           // Redirect stdin to pipe read end
        close(fd[0]);

        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }

    return 0;
}
/*
   	OUTPUT::

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans17b.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans17b.c -o ans17b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans17b.out
     81     726    4702
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
