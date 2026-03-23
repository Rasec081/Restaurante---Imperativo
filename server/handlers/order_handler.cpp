//
// Created by gambo on 22/3/2026.
//

#include "order_handler.h"
#include "order_manager.h"
#include "models.h"
#include "json_utils.h"

using namespace std;
using json = nlohmann::json;

void handleAddOrder(int client_socket, json request) {
    /*
     * validar numeros de mesa siempre
     */

    int mesa = request["mesa"];

    if (mesa <= 0 || mesa > getTotalMesas()) {
        json error;
        error["status"] = "ERROR";
        error["message"] = "Mesa inválida";

        sendJson(client_socket, error);
        return;
    }

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

    addOrder(orden);

    json response;
    response["status"] = "OK";
    response["message"] = "ORDER_ADDED";

    sendJson(client_socket, response);
}

void handleGetOrders(int client_socket) {
    vector<Orden> orders = getOrders();

    json response;
    response["status"] = "OK";

    for (auto &o : orders) {
        json ordenJson;
        ordenJson["id"] = o.id;
        ordenJson["mesa"] = o.numeroMesa;
        ordenJson["estado"] = o.estado ? "Completa" : "Pendiente";

        response["orders"].push_back(ordenJson);
    }

    sendJson(client_socket, response);
}

void handleCompleteOrder(int client_socket, json request) {
    int id = request["id"];
    completeOrder(id);

    json response;
    response["status"] = "OK";
    response["message"] = "ORDER_COMPLETED";

    sendJson(client_socket, response);
}

void handleUpdateOrder(int client_socket, json request) {
    /*
     * updateOrder
    *
     * validar numeros de mesa siempre
     */

    int id = request["id"];

    vector<ProductoEscogido> productos;

    for (auto& p : request["productos"]) {
        ProductoEscogido prod;
        prod.nombre = p["nombre"];
        prod.cantidad = p["cantidad"];
        productos.push_back(prod);
    }

    updateOrder(id, productos);

    json response;
    response["status"] = "OK";
    response["message"] = "ORDER_UPDATED";

    sendJson(client_socket, response);
}

void handleDeleteOrder(int client_socket, json request) {
    /*
     * borrar orden
     */

    int id = request["id"];
    deleteOrder(id);

    json response;
    response["status"] = "OK";
    response["message"] = "ORDER_DELETED";

    sendJson(client_socket, response);
}

void handleGetOrderDetail(int client_socket, json request) {
    int id = request["id"];

    Orden o = getOrderById(id);

    json response;

    if (o.id == 0) {
        response["status"] = "ERROR";
        response["message"] = "Order not found";
        sendJson(client_socket, response);
        return;
    }

    response["status"] = "OK";

    json ordenJson;
    ordenJson["id"] = o.id;
    ordenJson["mesa"] = o.numeroMesa;

    for (auto& p : o.productos) {
        json prod;
        prod["nombre"] = p.nombre;
        prod["cantidad"] = p.cantidad;
        ordenJson["productos"].push_back(prod);
    }

    response["order"] = ordenJson;

    sendJson(client_socket, response);
}