//
// Created by gambo on 22/3/2026.
//
#include <unistd.h>
#include <sys/socket.h>

#include "network_server.h"
#include "order_manager.h"
#include "product_manager.h"

int main() {
    initOrderManager();
    initOrderManager();

    int server_socket = createServer();

    //le metemos los productos antes de que se coencten los clientes
    addProducts();

    while(true) {

        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) continue;

        pid_t pid = fork();

        if(pid == 0) {
            close(server_socket);
            handleClient(client_socket);
        }
        else {
            close(client_socket);
        }
    }

    return 0;
}