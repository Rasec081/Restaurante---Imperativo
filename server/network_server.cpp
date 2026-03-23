#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

//#include "network_server.h"
#include "handlers/order_handler.h"
#include "handlers/product_handler.h"

using namespace std;
using json = nlohmann::json;

void handleClient(int client_socket) {

    cout << "Client connected\n";

    char buffer[2048];

    while(true) {

        memset(buffer, 0, sizeof(buffer));

        int bytes = recv(client_socket, buffer, sizeof(buffer), 0);

        if (bytes <= 0) {
            cout << "Cliente desconectado\n";
            break;
        }

        string msg(buffer);
        cout << "Mensaje recibido: " << msg << endl;

        try {
            json request = json::parse(msg);
            string type = request["type"];

            if (type == "ADD_ORDER") {
                handleAddOrder(client_socket, request);
            }
            else if (type == "GET_ORDERS") {
                handleGetOrders(client_socket);
            }
            else if (type == "COMPLETE_ORDER") {
                handleCompleteOrder(client_socket, request);
            }
            else if (type == "UPDATE_ORDER") {
                handleUpdateOrder(client_socket, request);
            }
            else if (type == "DELETE_ORDER") {
                handleDeleteOrder(client_socket, request);
            }
            else if (type == "GET_PRODUCTS") {
                handleGetProducts(client_socket);
            }
            else if (type == "ADD_PRODUCT") {
                handleAddProduct(client_socket, request);
            }
            else if (type == "UPDATE_PRODUCT") {
                handleUpdateProduct(client_socket, request);
            }
            else if (type == "DELETE_PRODUCT") {
                handleDeleteProduct(client_socket, request);
            }

        } catch (exception &e) {
            cout << "Error parsing JSON: " << e.what() << endl;

            json error;
            error["status"] = "ERROR";
            error["message"] = "Invalid JSON";

            sendJson(client_socket, error);
        }
    }

    close(client_socket);
    exit(0);
}

int createServer() {

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket < 0){
        perror("Socket error");
        exit(1);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if(bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Bind failed");
        exit(1);
    }

    listen(server_socket, 5);
    cout << "Server listening...\n";

    return server_socket;
}

int main() {
    initOrderManager();
    // Aqui poner el init del product

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