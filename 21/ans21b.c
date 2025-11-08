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

    // Open FIFO1 for reading and FIFO2 for writing
    fd1 = open(FIFO1, O_RDONLY);
    fd2 = open(FIFO2, O_WRONLY);

    // Read message from process1
    read(fd1, buffer, sizeof(buffer));
    printf("Process2: Received <- %s\n", buffer);

    // Send response to process1
    char *msg2 = "Hello from Process 2!";
    write(fd2, msg2, strlen(msg2) + 1);
    printf("Process2: Sent -> %s\n", msg2);

    close(fd1);
    close(fd2);
    return 0;
}
/*
  OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans21b.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans21b.c -o ans21b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans21b.out
Process2: Received <- Hello from Process 1!
Process2: Sent -> Hello from Process 2!

 */
