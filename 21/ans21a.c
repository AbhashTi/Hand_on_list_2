/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
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

#define FIFO1 "fifo1"   // process1 → process2
#define FIFO2 "fifo2"   // process2 → process1

int main() {
    int fd1, fd2;
    char buffer[100];

    // Create the FIFOs if they don’t exist
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    // Open FIFO1 for writing and FIFO2 for reading
    fd1 = open(FIFO1, O_WRONLY);
    fd2 = open(FIFO2, O_RDONLY);

    // Send message to process2
    char *msg1 = "Hello from Process 1!";
    write(fd1, msg1, strlen(msg1) + 1);
    printf("Process1: Sent -> %s\n", msg1);

    // Read response from process2
    read(fd2, buffer, sizeof(buffer));
    printf("Process1: Received <- %s\n", buffer);

    close(fd1);
    close(fd2);
    return 0;
}
/*
  OUTPUT:: 
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans21a.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans21a.c -o ans21a.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans21a.out
Process1: Sent -> Hello from Process 1!
Process1: Received <- Hello from Process 2!

 */
