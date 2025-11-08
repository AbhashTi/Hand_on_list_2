/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    // Generate a unique key
    key = ftok(".", 'B');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create or get the message queue
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Get message queue information
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message Queue Info:\n");
    printf("a. Access Permissions: %o\n", buf.msg_perm.mode);
    printf("b. UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);

    printf("c. Last msg sent time : %s",
           (buf.msg_stime ? ctime(&buf.msg_stime) : "Not yet sent\n"));
    printf("   Last msg received time : %s",
           (buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not yet received\n"));

    printf("d. Last change time : %s", ctime(&buf.msg_ctime));

    printf("e. Current number of bytes in queue: %lu\n", buf.__msg_cbytes);
    printf("f. Number of messages in queue: %lu\n", buf.msg_qnum);
    printf("g. Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);

    printf("h. PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("   PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}
/*
  OUTPUT::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans25.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans25.c -o ans25.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans25.out
Message Queue Info:
a. Access Permissions: 666
b. UID: 1000, GID: 1000
c. Last msg sent time : Not yet sent
   Last msg received time : Not yet received
d. Last change time : Tue Sep 30 14:14:56 2025
e. Current number of bytes in queue: 0
f. Number of messages in queue: 0
g. Maximum number of bytes allowed: 16384
h. PID of last msgsnd: 0
   PID of last msgrcv: 0
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
 */
