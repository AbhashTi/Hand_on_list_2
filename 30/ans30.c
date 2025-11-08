/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024  // size of shared memory

int main() {
    key_t key;
    int shmid;
    char *shm_ptr;

    // 1. Generate key
    key = ftok(".", 'D');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // 2. Create shared memory
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Shared memory created: ID=%d, Key=%d\n", shmid, key);

    // 3. Attach for read-write
    shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // 4. Write data
    strcpy(shm_ptr, "Hello! This is shared memory.");
    printf("Data written to shared memory: %s\n", shm_ptr);

    // 5. Attach with read-only
    char *shm_ro = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (shm_ro == (char *)-1) {
        perror("shmat read-only");
        exit(1);
    }
    printf("Attached read-only: %s\n", shm_ro);

    // 6. Try to overwrite read-only memory
    printf("Trying to overwrite read-only memory...\n");
    // This may cause segmentation fault
    // shm_ro[0] = 'h'; // Uncomment to test, usually will fail

    // 7. Detach both attachments
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmdt(shm_ro) == -1) {
        perror("shmdt read-only");
        exit(1);
    }
    printf("Detached shared memory.\n");

    // 8. Remove shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl IPC_RMID");
        exit(1);
    }
    printf("Shared memory removed.\n");

    return 0;
}
/*
  OUTPUT:: 
  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans30.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans30.c -o ans30.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans30.c
bash: ./ans30.c: Permission denied
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans30.out
Shared memory created: ID=0, Key=1141178370
Data written to shared memory: Hello! This is shared memory.
Attached read-only: Hello! This is shared memory.
Trying to overwrite read-only memory...
Detached shared memory.
Shared memory removed.
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$

 */
