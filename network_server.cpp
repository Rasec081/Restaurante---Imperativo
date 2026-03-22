#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <vector>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

#include "server/order_manager.h"

using namespace std;
using json = nlohmann::json;

OrderManager orderManager;

int main() {

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket < 0){
        perror("Socket error");
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if(bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Bind failed");
        return 1;
    }

    listen(server_socket, 5);
    cout << "Server listening...\n";

    while(true) {

        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) continue;

        pid_t pid = fork();

        if(pid == 0) {
            close(server_socket);
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

                    // ========================
                    // ADD ORDER
                    // ========================
                    if (type == "ADD_ORDER") {

                        int mesa = request["mesa"];

                        vector<ProductoEscogido> productos;

                        for (auto& p : request["productos"]) {
                            ProductoEscogido prod;
                            prod.nombre = p["nombre"];
                            prod.cantidad = p["cantidad"];
                            productos.push_back(prod);
                        }

                        Orden orden;
                        orden.id = 0;
                        orden.numeroMesa = mesa;
                        orden.productos = productos;

                        orderManager.addOrder(orden);

                        json response;
                        response["status"] = "OK";
                        response["message"] = "ORDER_ADDED";

                        string resp = response.dump();
                        send(client_socket, resp.c_str(), resp.size(), 0);
                    }

                    // ========================
                    // GET ORDERS
                    // ========================
                    else if (type == "GET_ORDERS") {

                        vector<Orden> orders = orderManager.getOrders();

                        json response;
                        response["status"] = "OK";

                        for (auto &o : orders) {

                            json ordenJson;
                            ordenJson["id"] = o.id;
                            ordenJson["mesa"] = o.numeroMesa;
                            ordenJson["estado"] = o.estado ? "Completa" : "Pendiente";

                            response["orders"].push_back(ordenJson);
                        }

                        string resp = response.dump();
                        send(client_socket, resp.c_str(), resp.size(), 0);
                    }

                    // ========================
                    // COMPLETE ORDER
                    // ========================
                    else if (type == "COMPLETE_ORDER") {

                        int id = request["id"];
                        orderManager.completeOrder(id);

                        json response;
                        response["status"] = "OK";
                        response["message"] = "ORDER_COMPLETED";

                        string resp = response.dump();
                        send(client_socket, resp.c_str(), resp.size(), 0);
                    }

                } catch (exception &e) {
                    cout << "Error parsing JSON: " << e.what() << endl;

                    json error;
                    error["status"] = "ERROR";
                    error["message"] = "Invalid JSON";

                    string resp = error.dump();
                    send(client_socket, resp.c_str(), resp.size(), 0);
                }
            }

            close(client_socket);
            exit(0);
        }
        else {
            close(client_socket);
        }
    }

    return 0;
}