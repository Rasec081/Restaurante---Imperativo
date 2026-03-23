//
// Created by gambo on 22/3/2026.
//

#include <string>
#include <sys/socket.h>
#include "json_utils.h"

using namespace std;

void sendJson(int client_socket, nlohmann::json response) {
    string resp = response.dump();
    send(client_socket, resp.c_str(), resp.size(), 0);
}