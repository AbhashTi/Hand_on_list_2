/*
============================================================================
Name : ans14.c
Author : Abhash Tiwari
Description :Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor. 
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; // fd[0] = read end, fd[1] = write end
    char write_msg[] = "Hello from pipe!";
    char read_msg[100];

    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    // Write to the pipe
    write(fd[1], write_msg, strlen(write_msg) + 1); // +1 to include null terminator
    printf("Written to pipe: %s\n", write_msg);

    // Read from the pipe
    read(fd[0], read_msg, sizeof(read_msg));
    printf("Read from pipe: %s\n", read_msg);

    // Close pipe ends
    close(fd[0]);
    close(fd[1]);

    return 0;
}
/*
   OUTPUT::

   saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans14.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans14.c -o ans14.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans14.out
Written to pipe: Hello from pipe!
Read from pipe: Hello from pipe!
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
