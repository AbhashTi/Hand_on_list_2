/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
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
    struct msqid_ds buf;

    // Generate key (must match existing queue)
    key = ftok(".", 'C');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get existing message queue
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Get current message queue info
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl - IPC_STAT");
        exit(1);
    }

    printf("Current permissions: %o\n", buf.msg_perm.mode);

    // Change permission to 600 (read/write for owner only)
    buf.msg_perm.mode = 0600;

    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("msgctl - IPC_SET");
        exit(1);
    }

    printf("Message queue permissions updated successfully!\n");

    // Verify
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl - IPC_STAT");
        exit(1);
    }
    printf("New permissions: %o\n", buf.msg_perm.mode);

    return 0;
}
/*
  output::
  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans28.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans28.c -o ans28.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans28.out
Current permissions: 666
Message queue permissions updated successfully!
New permissions: 600
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x41050002 0          saurabh    666        0            0
0x42050002 1          saurabh    666        0            0
0x43050002 2          saurabh    600        0            0

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
