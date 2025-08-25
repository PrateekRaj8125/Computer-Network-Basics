/*
Connection Oriented Socket Programming Lab
Q: Write a C program to implement a simple TCP server that accepts connections from a client, receives messages, and sends responses.

This program creates a TCP server that listens on a port provided via command line argument.
It accepts a client connection, receives messages from the client, and allows the user to reply.
If the client sends "close", the server closes the connection.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAXLINE];

    // Step 1: Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Set socket options to allow address reuse
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Step 3: Set server address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    // Step 4: Bind socket to given port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Step 5: Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %s...\n", argv[1]);

    // Step 6: Accept a connection from client
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connected to client: IP %s, Port %d\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Step 7: Message exchange loop
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int valread = read(new_socket, buffer, MAXLINE - 1);
        if (valread <= 0) break;
        buffer[valread] = '\0';
        printf("Client: %s\n", buffer);

        // If client sends "close", exit loop and close connection
        if (strcmp(buffer, "close") == 0) {
            printf("Closing connection...\n");
            break;
        }

        // Get reply from server user and send to client
        printf("Enter reply: ");
        fgets(buffer, MAXLINE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        send(new_socket, buffer, strlen(buffer), 0);
    }

    // Step 8: Close sockets
    close(new_socket);
    close(server_fd);
    return 0;
}
