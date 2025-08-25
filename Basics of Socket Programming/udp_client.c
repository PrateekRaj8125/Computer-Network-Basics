/*
** A datagram "client" demo
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVERPORT 8080 // the port users will be connecting to

int main() {
    int sockfd;
    struct sockaddr_in their_addr; // Server address information
    int numbytes;
    char arg[30];

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set server address parameters
    memset(&their_addr, 0, sizeof(their_addr));
    their_addr.sin_family = AF_INET; // host byte order
    their_addr.sin_port = htons(SERVERPORT); // short, network byte order
    their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Get message from user
    printf("Enter a message:\n");
    if (fgets(arg, sizeof(arg), stdin) == NULL) {
        printf("Error reading input.\n");
        close(sockfd);
        exit(1);
    }

    size_t len = strlen(arg);
    if (len > 0 && arg[len - 1] == '\n') {
        arg[len - 1] = '\0'; // Remove the newline character from the input
    }

    // Send message to server
    if ((numbytes = sendto(sockfd, arg, strlen(arg), 0,
            (struct sockaddr *)&their_addr, sizeof(their_addr))) == -1) {
        perror("sendto");
        close(sockfd);
        exit(1);
    }

    printf("Sent %d bytes to %s\n", numbytes, inet_ntoa(their_addr.sin_addr));

    close(sockfd);
    return 0;
}
