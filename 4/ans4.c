
/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description :  Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

// Function to read timestamp counter
static __inline__ unsigned long long rdtsc(void) {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    int i;

    // Take start timestamp
    start = rdtsc();

    // Run 100 getppid() system calls
    for (i = 0; i < 100; i++) {
        getppid();
    }

    // Take end timestamp
    end = rdtsc();

    printf("Cycles taken for 100 getppid() calls: %llu\n", (end - start));
    printf("Average cycles per getppid(): %llu\n", (end - start) / 100);

    return 0;
}

/*
      OUTPUT::
 
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans4.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans4.c -o ans4.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans4.out
Cycles taken for 100 getppid() calls: 61061
Average cycles per getppid(): 610
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$
*/
