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

int main() {
    key_t key = ftok(".", 'S');
    if (key == -1) { perror("ftok"); exit(1); }

    int semid = semget(key, 1, 0666);
    if (semid == -1) { perror("semget"); exit(1); }

    struct sembuf p_op = {0, -1, 0}; // decrement semaphore

    printf("Performing P (wait) operation...\n");
    if (semop(semid, &p_op, 1) == -1) { perror("semop P"); exit(1); }

    printf("P (wait) operation done.\n");
    return 0;
}
/*
  OUTPUT::
  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans32b.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans32b.c -o ans32b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans32b.out
Performing P (wait) operation...
P (wait) operation done.
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$


 */
