/*
============================================================================
Name : ans2.c
Author : Abhash Tiwari
discription: 2. Write a program to print the system resource limits. Use getrlimit system call.
Date: 28th sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

// Helper function to print a limit
void print_limit(const char *name, int resource) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0) {
        printf("%-20s: Soft = ", name);

        if (limit.rlim_cur == RLIM_INFINITY)
            printf("INFINITY");
        else
            printf("%ld", (long) limit.rlim_cur);

        printf(", Hard = ");

        if (limit.rlim_max == RLIM_INFINITY)
            printf("INFINITY\n");
        else
            printf("%ld\n", (long) limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    printf("=== System Resource Limits ===\n");

    print_limit("CPU time", RLIMIT_CPU);
    print_limit("File size", RLIMIT_FSIZE);
    print_limit("Data seg size", RLIMIT_DATA);
    print_limit("Stack size", RLIMIT_STACK);
    print_limit("Core file size", RLIMIT_CORE);
    print_limit("Resident set", RLIMIT_RSS);
    print_limit("Processes", RLIMIT_NPROC);
    print_limit("Open files", RLIMIT_NOFILE);
    print_limit("Address space", RLIMIT_AS);
    print_limit("Locked memory", RLIMIT_MEMLOCK);
    print_limit("File locks", RLIMIT_LOCKS);
    print_limit("Signals pending", RLIMIT_SIGPENDING);
    print_limit("Message queue", RLIMIT_MSGQUEUE);
    print_limit("Nice priority", RLIMIT_NICE);
    print_limit("Realtime priority", RLIMIT_RTPRIO);
    print_limit("RT time", RLIMIT_RTTIME);

    return 0;
}

/* OUTPUT:: 
 
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans2.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans2.c -o ans2.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans2.out
=== System Resource Limits ===
CPU time            : Soft = INFINITY, Hard = INFINITY
File size           : Soft = INFINITY, Hard = INFINITY
Data seg size       : Soft = INFINITY, Hard = INFINITY
Stack size          : Soft = 8388608, Hard = INFINITY
Core file size      : Soft = 0, Hard = INFINITY
Resident set        : Soft = INFINITY, Hard = INFINITY
Processes           : Soft = 29896, Hard = 29896
Open files          : Soft = 1024, Hard = 1048576
Address space       : Soft = INFINITY, Hard = INFINITY
Locked memory       : Soft = 1000243200, Hard = 1000243200
File locks          : Soft = INFINITY, Hard = INFINITY
Signals pending     : Soft = 29896, Hard = 29896
Message queue       : Soft = 819200, Hard = 819200
Nice priority       : Soft = 0, Hard = 0
Realtime priority   : Soft = 0, Hard = 0
RT time             : Soft = INFINITY, Hard = INFINITY
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ 

 */
