#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <nlohmann/json.hpp>
#include "network_client.h"
#include <iostream>


using json = nlohmann::json;
using namespace std;

int client_socket;

void initConnection() {
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(client_socket, (struct sockaddr *)&server, sizeof(server));
}

json sendJSON(json request) {
    string msg = request.dump();
    send(client_socket, msg.c_str(), msg.size(), 0);

    char buffer[2048];
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);

    cout << "\nRESPUESTA:\n" << buffer << endl;

    json response;

    try {
        response = json::parse(buffer);
    } catch (...) {
        cout << "Error parseando JSON\n";
        response["status"] = "ERROR";
        response["message"] = "Invalid JSON";
    }

    return response;
}

/*
 * no deberia de haber un while que este esperando escuchar si el server nos dice algo?
 *
 */