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
#include <stdio.h>

int main() {
    const char *fifo = "myfifo6";

    if (mkfifo(fifo, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO created using mkfifo library function: %s\n", fifo);
    return 0;
}
/*
   OUTPUT::

   saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans19e.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans19e.c -o ans19e.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans19e.out
FIFO created using mkfifo library function: myfifo6

 */
