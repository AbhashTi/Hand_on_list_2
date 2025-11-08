/*
============================================================================
Name : ans3.c
0Author : Abhash Tiwari 
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
#include <fcntl.h>

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
        close(fd[0]); // Close unused read end
        int newfd = fcntl(fd[1], F_DUPFD, 1); // Duplicate fd to >=1 (stdout)
        if (newfd != 1) {
            dup2(newfd, 1); // Ensure it's stdout
        }
        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    } else {
        // Parent: wc
        close(fd[1]); // Close unused write end
        int newfd = fcntl(fd[0], F_DUPFD, 0); // Duplicate fd to >=0 (stdin)
        if (newfd != 0) {
            dup2(newfd, 0); // Ensure it's stdin
        }
        close(fd[0]);

        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }

    return 0;
}
/*
   	OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans17c.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans17c.c-o ans17c.out
/usr/bin/ld: cannot find ans17c.c-o: No such file or directory
/usr/bin/ld: cannot find ans17c.out: No such file or directory
collect2: error: ld returned 1 exit status
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans17c.c -o as17c.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./as17c.out
     83     744    4821
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 

 */
