/*
============================================================================
Name : ans2.c
Author : Abhash Tiwari
disicription: Write a program to set (any one) system resource limit. Use setrlimit system call
Date: 28th sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rlimit limit;

    // First get the current limit
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("Before: RLIMIT_NOFILE -> Soft = %ld, Hard = %ld\n",
           (long)limit.rlim_cur, (long)limit.rlim_max);

    // Change the soft limit (hard limit can only be lowered by non-root users)
    limit.rlim_cur = 512;   // set soft limit to 512
    // limit.rlim_max = 1024; // optional: can set hard limit if root

    if (setrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("setrlimit");
        exit(1);
    }

    // Verify
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("After : RLIMIT_NOFILE -> Soft = %ld, Hard = %ld\n",
           (long)limit.rlim_cur, (long)limit.rlim_max);

    return 0

}
