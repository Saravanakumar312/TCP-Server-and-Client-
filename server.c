#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 5

int main() {
    int sockfd, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    socklen_t client_len = sizeof(client_addr);

    // 1. Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    // 3. Bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // 4. Listen for incoming connections
    if (listen(sockfd, BACKLOG) < 0) {
        perror("Listen failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);

    // 5. Main loop to accept and handle connections
    while (1) {
        // Accept a connection
        if ((client_sock = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accept failed");
            continue; // Continue accepting other connections
        }
        printf("Client connected.\n");

        // Receive data from the client
        ssize_t recv_len = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
        if (recv_len < 0) {
            perror("Receive failed");
        } else {
            buffer[recv_len] = '\0'; // Null-terminate the received data
            printf("Client: %s\n", buffer);
            
            // Send a response to the client
            char *message = "Hello from server";
            if (send(client_sock, message, strlen(message), 0) < 0) {
                perror("Send failed");
            }
        }

        // Close the client socket
        close(client_sock);
        printf("Client disconnected.\n");
    }

    // Close the server socket (this line will never be reached in this example)
    close(sockfd);

    return 0;
}
