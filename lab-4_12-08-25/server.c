#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAXLINE];

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    // Bind socket to given port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %s...\n", argv[1]);

    // Accept a connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connected to client: IP %s, Port %d\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Message exchange
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int valread = read(new_socket, buffer, MAXLINE - 1);
        if (valread <= 0) break;
        buffer[valread] = '\0';
        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "close") == 0) {
            printf("Closing connection...\n");
            break;
        }

        printf("Enter reply: ");
        fgets(buffer, MAXLINE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
