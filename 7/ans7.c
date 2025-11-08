
/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a simple program to print the created thread ids
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function
void* thread_function(void* arg) {
    int id = *((int*)arg);
    printf("Thread %d created with ID: %lu\n", id, pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];
    int ids[3];
    int i;

    // Create 3 threads
    for (i = 0; i < 3; i++) {
        ids[i] = i + 1; // Thread IDs: 1, 2, 3
        if (pthread_create(&threads[i], NULL, thread_function, &ids[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Main thread ID: %lu\n", pthread_self());
    return 0;
}

/*
   OUTPUT::

saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans7.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans7.c -o ans7.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans7.out
Thread 1 created with ID: 124683949176512
Thread 2 created with ID: 124683940783808
Thread 3 created with ID: 124683932391104
Main thread ID: 124683951720256
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
