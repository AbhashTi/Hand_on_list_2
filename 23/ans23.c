/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description :Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef F_GETPIPE_SZ
#define F_GETPIPE_SZ 1032   // define manually if missing
#endif

int main() {
    struct rlimit rl;

    // 1. Maximum number of open files per process
    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("Maximum number of open files per process:\n");
    printf("  Soft limit : %ld\n", (long)rl.rlim_cur);
    printf("  Hard limit : %ld\n", (long)rl.rlim_max);

    // 2. Pipe size
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    int pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
    if (pipe_size == -1) {
        perror("fcntl");
    } else {
        printf("Size of a pipe (circular buffer): %d bytes\n", pipe_size);
    }

    close(fd[0]);
    close(fd[1]);

    return 0;
}

/*
  OUTPUT::
	saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans23.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans23.c -o ans23.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans23.out
Maximum number of open files per process:
  Soft limit : 1024
  Hard limit : 1048576
Size of a pipe (circular buffer): 65536 bytes
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */
