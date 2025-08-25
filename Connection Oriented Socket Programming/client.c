/*
Connection Oriented Socket Programming Lab
Q: Write a C program to implement a simple TCP client that connects to a server, sends messages, and receives responses.

This program creates a TCP client that connects to a server using IP and port provided via command line arguments.
It allows the user to send messages to the server and prints the server's response.
If the user enters "close", the client closes the connection.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAXLINE];

    // Step 1: Create TCP socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Step 2: Set server address parameters
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Step 3: Convert IP address from text to binary form
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Step 4: Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server %s:%s\n", argv[1], argv[2]);

    // Step 5: Communication loop
    while (1) {
        printf("Enter message: ");
        fgets(buffer, MAXLINE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        send(sock, buffer, strlen(buffer), 0); // Send message to server

        // If user enters "close", exit loop and close connection
        if (strcmp(buffer, "close") == 0) {
            printf("Closing connection...\n");
            break;
        }

        // Receive response from server
        memset(buffer, 0, sizeof(buffer));
        int valread = read(sock, buffer, MAXLINE - 1);
        if (valread <= 0) break;
        buffer[valread] = '\0';
        printf("Server: %s\n", buffer);
    }

    // Step 6: Close socket
    close(sock);
    return 0;
}
