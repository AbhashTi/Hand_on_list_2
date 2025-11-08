/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 28th Aug, 2025.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    const char *fifo = "myfifo5";

    if (mknod(fifo, S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        return 1;
    }

    printf("FIFO created using mknod system call: %s\n", fifo);
    return 0;
}
/*
  OUTPUT::

  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans19d.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans19d.c -o ans19d.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans19d.out
FIFO created using mknod system call: myfifo5

 */

