//
// Created by gambo on 22/3/2026.
//

#ifndef PROJECT1_PRODUCT_HANDLER_H
#define PROJECT1_PRODUCT_HANDLER_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;

void handleGetProducts(int client_socket);
void handleAddProduct(int client_socket, json request);
void handleUpdateProduct(int client_socket, json request);
void handleDeleteProduct(int client_socket, json request);

#endif //PROJECT1_PRODUCT_HANDLER_H