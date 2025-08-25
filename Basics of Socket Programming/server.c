/*
Socket Programming Lab
Q: Write a C program to implement a simple UDP server that receives a message from a client and sends a response back.

This program creates a UDP server that listens on a specific port, receives a message from a client, prints the message, and sends a response.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT	 8080      // Port number for server
#define MAXLINE  1024      // Maximum buffer size

int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    // Step 1: Create UDP socket
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Clear server and client address structures
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Step 3: Set server address parameters
    servaddr.sin_family = AF_INET;           // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;   // Any incoming interface
    servaddr.sin_port = htons(PORT);         // Port in network byte order

    // Step 4: Bind the socket with the server address
    // This assigns the server a definite port and address.
    if (bind(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) < 0 ) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;
    len = sizeof(cliaddr);

    // Step 5: Receive message from client
    // We pass the client address structure to capture the client's IP and port.
    // In UDP, there are no connections, so we need to get the address from the received packet.
    n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *) &cliaddr, &len);
    buffer[n] = '\0'; // Null-terminate received message
    printf("Client : %s\n", buffer);

    // Step 6: Send response to client
    sendto(sockfd, hello, strlen(hello), 0, (struct sockaddr *) &cliaddr, len);
    printf("Hello message sent.\n");

    // Step 7: Print client port
    printf("The client port is %d\n", ntohs(cliaddr.sin_port));

    close(sockfd);
    return 0;
}