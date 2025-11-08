/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari

Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main() {
    key_t key = ftok(".", 'S'); // unique key
    if (key == -1) { perror("ftok"); exit(1); }

    // Create 1 semaphore
    int semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) { perror("semget"); exit(1); }

    // Initialize semaphore value (1 for binary semaphore)
    union semun sem_val;
    sem_val.val = 1;
    if (semctl(semid, 0, SETVAL, sem_val) == -1) {
        perror("semctl"); exit(1);
    }

    printf("Semaphore created: ID=%d, initialized to %d\n", semid, sem_val.val);
    return 0;
}
/*
  OUTPUT::
  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans32a.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans32a.c -o ans32a.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans32a.out
Semaphore created: ID=2, initialized to 1
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
