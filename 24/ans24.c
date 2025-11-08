/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to create a message queue and print the key and message queue id.
Date: 28th Aug, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    // Generate a unique key using ftok
    key = ftok(".", 'A');   // "." = current directory, 'A' = project identifier
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a message queue with read & write permission
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message Queue created successfully!\n");
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}
/*
  output::

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans24.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans24.c -O ans24.out
/usr/bin/ld: cannot find ans24.out: No such file or directory
collect2: error: ld returned 1 exit status
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans24.c -o ans24.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans24.out
Message Queue created successfully!
Key: 1090846722
Message Queue ID: 0
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 

 */
