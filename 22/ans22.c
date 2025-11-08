/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO. 
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <errno.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char buffer[100];
    fd_set readfds;
    struct timeval tv;
    int ret;

    // Create FIFO if not exists
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(1);
        }
    }

    // Open FIFO for reading (non-blocking so open won’t hang without writer)
    fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Setup select()
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    tv.tv_sec = 10;   // 10 second timeout
    tv.tv_usec = 0;

    printf("Waiting for data on FIFO for 10 seconds...\n");

    ret = select(fd + 1, &readfds, NULL, NULL, &tv);

    if (ret == -1) {
        perror("select");
        close(fd);
        exit(1);
    } else if (ret == 0) {
        printf("Timeout: No data written to FIFO in 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            int n = read(fd, buffer, sizeof(buffer));
            if (n > 0) {
                buffer[n] = '\0';
                printf("Data received: %s\n", buffer);
            } else {
                printf("No data read (writer may have closed FIFO).\n");
            }
        }
    }

    close(fd);
    return 0;
}
/*
   OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans22.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans22.c -o ans22.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans22.out
Waiting for data on FIFO for 10 seconds...
Timeout: No data written to FIFO in 10 seconds.
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 
 */
