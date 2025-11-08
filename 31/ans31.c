/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description :  Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int val;               // value for SETVAL
    struct semid_ds *buf;  // buffer for IPC_STAT, IPC_SET
    unsigned short *array; // array for GETALL/SETALL
    struct seminfo *__buf; // Linux specific
};

int main() {
    key_t key_bin, key_count;
    int semid_bin, semid_count;
    union semun sem_val;

    // --------- Binary Semaphore ----------
    key_bin = ftok(".", 'B');
    if (key_bin == -1) {
        perror("ftok binary");
        exit(1);
    }

    // Create binary semaphore (1 semaphore)
    semid_bin = semget(key_bin, 1, IPC_CREAT | 0666);
    if (semid_bin == -1) {
        perror("semget binary");
        exit(1);
    }

    // Initialize binary semaphore to 1
    sem_val.val = 1;
    if (semctl(semid_bin, 0, SETVAL, sem_val) == -1) {
        perror("semctl binary");
        exit(1);
    }
    printf("Binary semaphore created: ID=%d, initialized to 1\n", semid_bin);

    // --------- Counting Semaphore ----------
    key_count = ftok(".", 'C');
    if (key_count == -1) {
        perror("ftok counting");
        exit(1);
    }

    int n = 5; // number of resources
    // Create counting semaphore with 1 semaphore (can extend to array later)
    semid_count = semget(key_count, 1, IPC_CREAT | 0666);
    if (semid_count == -1) {
        perror("semget counting");
        exit(1);
    }

    // Initialize counting semaphore to n (number of available resources)
    sem_val.val = n;
    if (semctl(semid_count, 0, SETVAL, sem_val) == -1) {
        perror("semctl counting");
        exit(1);
    }

    printf("Counting semaphore created: ID=%d, initialized to %d\n", semid_count, n);

    return 0;
}
/*
  OUTPUT::
  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans31.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans31.c -o ans31.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans31.out
Binary semaphore created: ID=0, initialized to 1
Counting semaphore created: ID=1, initialized to 5
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 

 */
