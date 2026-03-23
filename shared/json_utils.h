//
// Created by gambo on 22/3/2026.
//

#ifndef PROJECT1_JSON_UTILS_H
#define PROJECT1_JSON_UTILS_H

#include <nlohmann/json.hpp>

void sendJson(int client_socket, nlohmann::json response);

#endif //PROJECT1_JSON_UTILS_H