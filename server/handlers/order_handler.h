//
// Created by gambo on 22/3/2026.
//

#ifndef PROJECT1_ORDER_HANDLER_H
#define PROJECT1_ORDER_HANDLER_H

#pragma once
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void handleAddOrder(int client_socket, json request);
void handleGetOrders(int client_socket);
void handleCompleteOrder(int client_socket, json request);
void handleUpdateOrder(int client_socket, json request);
void handleDeleteOrder(int client_socket, json request);

#endif //PROJECT1_ORDER_HANDLER_H