//
// Created by gambo on 22/3/2026.
//

#include "product_handler.h"
#include "server/product_manager.h"
#include "shared/json_utils.h"

using namespace std;
using json = nlohmann::json;

void handleGetProducts(int client_socket) {
    /*
     * saber cuando el cliente me pide ver los platillos
     * y enviarselos
     */

    vector<Producto> productos = getProductos();

    json response;
    response["status"] = "OK";

    for (auto& p : productos) {
        json prod;
        prod["nombre"] = p.nombre;
        prod["precio"] = p.precio;

        response["productos"].push_back(prod);
    }

    sendJson(client_socket, response);
}

void handleAddProduct(int client_socket, json request) {
    /*
     * añadir producto
     */

    string nombre = request["nombre"];
    float precio = request["precio"];

    crearProducto(nombre, precio);

    json response;
    response["status"] = "OK";
    response["message"] = "PRODUCT_ADDED";

    sendJson(client_socket, response);
}

void handleUpdateProduct(int client_socket, json request) {
    /*
     * aeditar producto
     */

    string nombre = request["nombre"];

    if (request.contains("nuevoNombre")) {
        string nuevoNombre = request["nuevoNombre"];
        actualizarProducto(nombre, nuevoNombre);
    }

    if (request.contains("precio")) {
        float precio = request["precio"];
        actualizarProducto(nombre, precio);
    }

    json response;
    response["status"] = "OK";
    response["message"] = "PRODUCT_UPDATED";

    sendJson(client_socket, response);
}

void handleDeleteProduct(int client_socket, json request) {
    /*
     * eliminar producto
     */

    string nombre = request["nombre"];

    eliminarProducto(nombre);

    json response;
    response["status"] = "OK";
    response["message"] = "PRODUCT_DELETED";

    sendJson(client_socket, response);
}