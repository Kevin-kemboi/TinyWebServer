#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <sys/socket.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_html(int client_socket, const char *file_path) {
  FILE *html_file = fopen(file_path, "r");
  if (html_file == NULL) {
    perror("Error opening HTML file");
    return;
  }

  char buffer[BUFFER_SIZE];
  size_t bytes_read;

  char *http_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  send(client_socket, http_header, strlen(http_header), 0);

  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, html_file)) > 0) {
    send(client_socket, buffer, bytes_read, 0);
  }

  fclose(html_file);
}

int main() {
#ifdef _WIN32
  // Initialize Winsock for Windows
  WSADATA wsaData;
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    printf("WSAStartup failed\n");
    return 1;
  }
#endif

  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
#ifdef _WIN32
  int client_len = sizeof(client_addr);
#else
  socklen_t client_len = sizeof(client_addr);
#endif

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
#ifdef _WIN32
  if (server_socket == INVALID_SOCKET) {
    printf("Socket creation failed with error: %d\n", WSAGetLastError());
    WSACleanup();
    exit(EXIT_FAILURE);
  }
#else
  if (server_socket == -1) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }
#endif

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(server_socket, (struct sockaddr *)&server_addr,
           sizeof(server_addr)) < 0) {
#ifdef _WIN32
    printf("Bind failed with error: %d\n", WSAGetLastError());
    closesocket(server_socket);
    WSACleanup();
#else
    perror("Bind failed");
    close(server_socket);
#endif
    exit(EXIT_FAILURE);
  }

  if (listen(server_socket, 5) < 0) {
#ifdef _WIN32
    printf("Listen failed with error: %d\n", WSAGetLastError());
    closesocket(server_socket);
    WSACleanup();
#else
    perror("Listen failed");
    close(server_socket);
#endif
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  while (1) {
    client_socket =
        accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
#ifdef _WIN32
    if (client_socket == INVALID_SOCKET) {
      printf("Accept failed with error: %d\n", WSAGetLastError());
      continue;
    }
#else
    if (client_socket < 0) {
      perror("Accept failed");
      continue;
    }
#endif

    printf("Client connected\n");
    send_html(client_socket, "index.html");
#ifdef _WIN32
    closesocket(client_socket);
#else
    close(client_socket);
#endif
    printf("Client disconnected\n");
  }

#ifdef _WIN32
  closesocket(server_socket);
  WSACleanup();
#else
  close(server_socket);
#endif
  return 0;
}