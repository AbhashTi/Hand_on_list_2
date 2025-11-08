/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
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

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char *message = "Hello from Writer process via FIFO!\n";

    // Create FIFO if it does not exist
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
    }

    // Open FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Write message to FIFO
    write(fd, message, strlen(message) + 1);
    printf("Writer: Message sent: %s\n", message);

    close(fd);
    return 0;
}
/*
  	OUTPUT:: 
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans20a.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans20a.c -o ans20a.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans20a.out
Writer: Message sent: Hello from Writer process via FIFO!

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 
 */
