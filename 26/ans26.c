/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define message structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Generate a unique key
    key = ftok(".", 'C');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a message queue
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Prepare the message
    message.msg_type = 1;   // message type must be >0
    strcpy(message.msg_text, "Hello! This is a test message.");

    // Send message to the queue
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to queue (ID=%d, Key=%d): %s\n", msgid, key, message.msg_text);

    return 0;
}
/*
   	OUTPUT::

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans26.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans26.c -o ans26.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans26.out
Message sent to queue (ID=2, Key=1124401154): Hello! This is a test message.
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x41050002 0          saurabh    666        0            0
0x42050002 1          saurabh    666        0            0
0x43050002 2          saurabh    666        100          1

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */
