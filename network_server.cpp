#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {

    // Crear socket del servidor
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket < 0){
        perror("Socket error");
        return 1;
    }

    // Estructura de direccion del servidor
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Asociar direccion al socket
    if(bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Bind failed");
        return 1;
    }

    // Escuchar conexiones
    listen(server_socket, 5);

    printf("Server listening...\n");

    int client_number = 0;

    while(true) {

        int client_socket = accept(server_socket, NULL, NULL);


        client_number++;

        pid_t pid = fork();

        if(pid == 0) {
            // Proceso hijo

            close(server_socket);
            printf("Client %d connected\n", client_number);

            // Buffer para recibir datos
            char buffer[1024];

            while(true) {

                memset(buffer,0,sizeof(buffer));

                int bytes = recv(client_socket, buffer, sizeof(buffer)-1, 0);

                if(bytes <= 0)
                    break;

                printf("Client %d: %s", client_number, buffer);

                // Enviar respuesta al cliente
                send(client_socket,"Mensaje recibido",17,0);
            }

            printf("Client %d disconnected\n", client_number);
            close(client_socket);
            exit(0);
        }
        else {
            // Proceso padre
            close(client_socket);
        }
    }

    return 0;
}