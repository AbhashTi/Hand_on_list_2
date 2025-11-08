/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to remove the message queue.
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

    // Generate the key (must match the queue to remove)
    key = ftok(".", 'C');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get the message queue ID
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl - IPC_RMID");
        exit(1);
    }

    printf("Message queue (ID=%d, Key=%d) removed successfully!\n", msgid, key);

    return 0;
}
/*
  OUTPUT::
  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans29.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans29.c -o ans29.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans29.out
Message queue (ID=2, Key=1124401154) removed successfully!
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x41050002 0          saurabh    666        0            0
0x42050002 1          saurabh    666        0            0

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */
