/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : . Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

// Message structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Generate key (must match sender)
    key = ftok(".", 'C');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get message queue
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("=== Blocking receive (flag=0) ===\n");
    // Receive message (blocking)
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 0, 0) == -1) {
        perror("msgrcv");
    } else {
        printf("Received message: %s\n", message.msg_text);
    }

    printf("\n=== Non-blocking receive (flag=IPC_NOWAIT) ===\n");
    // Try to receive message (non-blocking)
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 0, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG)
            printf("No message available (non-blocking)\n");
        else
            perror("msgrcv");
    } else {
        printf("Received message: %s\n", message.msg_text);
    }

    return 0;
}
/*
   saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans27.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans27.c -o ans27.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans27.out
=== Blocking receive (flag=0) ===
Received message: Hello! This is a test message.

=== Non-blocking receive (flag=IPC_NOWAIT) ===
No message available (non-blocking)
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 
 */
