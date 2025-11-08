/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a simple program to create three threads.
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void* thread_function(void* arg) {
    int id = *((int*)arg);
    printf("Hello from thread %d (TID: %lu)\n", id, pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];
    int ids[3];
    int i;

    // Create 3 threads
    for (i = 0; i < 3; i++) {
        ids[i] = i + 1; // Thread IDs 1, 2, 3
        if (pthread_create(&threads[i], NULL, thread_function, &ids[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished execution.\n");
    return 0;
}

/*
   OUTPUT::
    
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans6.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans6.c -o ans6.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans6.out
Hello from thread 1 (TID: 138232299779776)
Hello from thread 2 (TID: 138232291387072)
Hello from thread 3 (TID: 138232146687680)
All threads finished execution.
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
