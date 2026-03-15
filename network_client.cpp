#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {

    // Crear socket del cliente
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(client_socket < 0){
        perror("Socket error");
        return 1;
    }

    // Estructura del servidor (socker address)
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Convertir IP a formato de red
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    // Conectar al servidor
    if(connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server\n");

    char buffer[1024];
    // Enviar mensaje

    while(true){

        printf("Enter message: ");
        fgets(buffer,1024,stdin);

        send(client_socket, buffer, strlen(buffer),0);

        memset(buffer,0,sizeof(buffer));

        // Recibir respuestas del servidor
        recv(client_socket, buffer, sizeof(buffer)-1,0);

        printf("Server: %s\n", buffer);
    }

    // Cerrar conexion
    close(client_socket);

    return 0;
}