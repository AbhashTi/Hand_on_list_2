/*
============================================================================
Name : ans16.c
Author : Abhash Tiwari
Description :Write a program to send and receive data from parent to child vice versa. Use two way
communication  
Date: 28th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2], pipe2[2]; // pipe1: parent→child, pipe2: child→parent
    pid_t pid;
    char parent_msg[] = "Hello from parent!";
    char child_msg[] = "Hello from child!";
    char buffer[100];

    // Create pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2

        // Send message to child
        write(pipe1[1], parent_msg, strlen(parent_msg) + 1);
        printf("Parent sent: %s\n", parent_msg);

        // Receive reply from child
        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        // Close pipes
        close(pipe1[1]);
        close(pipe2[0]);
    } else {
        // Child process
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        // Receive message from parent
        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        // Send reply to parent
        write(pipe2[1], child_msg, strlen(child_msg) + 1);
        printf("Child sent: %s\n", child_msg);

        // Close pipes
        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}
/*
  OUTPUT::

  saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans16.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans16.c -o ans16.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans16.out
Parent sent: Hello from parent!
Child received: Hello from parent!
Child sent: Hello from child!
Parent received: Hello from child!
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$


 */
