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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char buffer[100];

    // Open FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read message from FIFO
    read(fd, buffer, sizeof(buffer));
    printf("Reader: Message received: %s\n", buffer);

    close(fd);
    return 0;
}
/*
   OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans20b.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans20b.c -o ans20b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans20b.out
Reader: Message received: Hello from Writer process via FIFO!

 */
