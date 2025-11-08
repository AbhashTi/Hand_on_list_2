/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe1[2], pipe2[2];

    // Create first pipe: ls -l | grep
    if (pipe(pipe1) == -1) {
        perror("pipe1 failed");
        exit(1);
    }

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child: executes 'ls -l'
        close(pipe1[0]);            // Close unused read end
        dup2(pipe1[1], 1);          // Redirect stdout to pipe1 write end
        close(pipe1[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    // Parent creates second pipe: grep | wc
    if (pipe(pipe2) == -1) {
        perror("pipe2 failed");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child: executes 'grep ^d'
        close(pipe1[1]);            // Close write end of pipe1
        dup2(pipe1[0], 0);          // Redirect stdin to pipe1 read end
        close(pipe1[0]);

        close(pipe2[0]);            // Close read end of pipe2
        dup2(pipe2[1], 1);          // Redirect stdout to pipe2 write end
        close(pipe2[1]);

        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep");
        exit(1);
    }

    // Parent: executes 'wc -l'
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[1]);                // Close write end of pipe2
    dup2(pipe2[0], 0);              // Redirect stdin to pipe2 read end
    close(pipe2[0]);

    execlp("wc", "wc", "-l", NULL);
    perror("execlp wc");
    exit(1);

    return 0;
}
/*
 	OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans18.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans18.c -o ans18.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans18.out
20
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */
