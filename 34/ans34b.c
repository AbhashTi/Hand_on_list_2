/*
============================================================================
Name : ans3.c
Author : Abhash Tiwari
Description : Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_sock = *(int *)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(client_sock, buffer, BUFFER_SIZE-1)) > 0) {
        buffer[n] = '\0';
        printf("Received: %s", buffer);
        write(client_sock, buffer, n); // echo back
    }

    close(client_sock);
    return NULL;
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) { perror("socket"); exit(1); }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind"); exit(1);
    }

    if (listen(server_fd, 5) < 0) { perror("listen"); exit(1); }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int *client_sock = malloc(sizeof(int));
        *client_sock = accept(server_fd, (struct sockaddr*)&address, &addrlen);
        if (*client_sock < 0) { perror("accept"); free(client_sock); continue; }

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, client_sock);
        pthread_detach(tid); // free resources when thread finishes
    }

    close(server_fd);
    return 0;
}
/*
  output::
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ vim ans34b.c
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ gcc ans34b.c -o ans34b.out
saurabh@saurabh-HP-Laptop-14s-er0xxx:~$ ./ans34b.out
bind: Address already in use
 */
