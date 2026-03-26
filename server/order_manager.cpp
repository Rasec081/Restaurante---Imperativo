#include "order_manager.h"
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

string FILE_PATH_ORDERS_ = "orders.json";

vector<Orden> leerOrdenesDesdeArchivo() {
    vector<Orden> ordenes;

    ifstream file(FILE_PATH_ORDERS_);
    if (!file.is_open()) {
        return ordenes;
    }

    json j;
    file >> j;

    for (auto& item : j) {
        Orden o;
        o.id = item["id"];
        o.numeroMesa = item["mesa"];
        o.estado = item["estado"];

        for (auto& p : item["productos"]) {
            ProductoEscogido pe;
            pe.nombre = p["nombre"];
            pe.cantidad = p["cantidad"];
            o.productos.push_back(pe);
        }

        ordenes.push_back(o);
    }

    return ordenes;
}

void guardarOrdenesEnArchivo(vector<Orden> ordenes) {
    json j = json::array();

    for (auto& o : ordenes) {
        json ordenJson;
        ordenJson["id"] = o.id;
        ordenJson["mesa"] = o.numeroMesa;
        ordenJson["estado"] = o.estado;

        for (auto& p : o.productos) {
            ordenJson["productos"].push_back({
                {"nombre", p.nombre},
                {"cantidad", p.cantidad}
            });
        }

        j.push_back(ordenJson);
    }

    ofstream file(FILE_PATH_ORDERS_);
    file << j.dump(4);
}

int obtenerSiguienteId(vector<Orden> ordenes) {
    int maxId = 0;
    for (auto& o : ordenes) {
        if (o.id > maxId) maxId = o.id;
    }
    return maxId + 1;
}

void addOrder(Orden orden) {
    vector<Orden> ordenes = leerOrdenesDesdeArchivo();

    orden.id = obtenerSiguienteId(ordenes);
    orden.estado = false;

    ordenes.push_back(orden);

    guardarOrdenesEnArchivo(ordenes);
}

void deleteOrder(int order_id) {
    vector<Orden> ordenes = leerOrdenesDesdeArchivo();

    for (int i = 0; i < ordenes.size(); i++) {
        if (ordenes[i].id == order_id) {
            ordenes.erase(ordenes.begin() + i);
            break;
        }
    }

    guardarOrdenesEnArchivo(ordenes);
}

void updateOrder(int order_id, vector<ProductoEscogido> productos) {
    vector<Orden> ordenes = leerOrdenesDesdeArchivo();

    for (auto& o : ordenes) {
        if (o.id == order_id) {
            o.productos = productos;
            break;
        }
    }

    guardarOrdenesEnArchivo(ordenes);
}

void completeOrder(int order_id) {
    vector<Orden> ordenes = leerOrdenesDesdeArchivo();

    for (auto& o : ordenes) {
        if (o.id == order_id) {
            o.estado = true;
            break;
        }
    }

    guardarOrdenesEnArchivo(ordenes);
}

vector<Orden> getOrders() {
    return leerOrdenesDesdeArchivo();
}

vector<Orden> getPendingOrders() {
    vector<Orden> ordenes = leerOrdenesDesdeArchivo();
    vector<Orden> pendientes;

    for (auto& o : ordenes) {
        if (!o.estado) {
            pendientes.push_back(o);
        }
    }

    return pendientes;
}

bool orderExists(int orderId) {
    vector<Orden> ordenes = leerOrdenesDesdeArchivo();

    for (auto& o : ordenes) {
        if (o.id == orderId) return true;
    }

    return false;
}

Orden getOrderById(int id) {
    vector<Orden> ordenes = leerOrdenesDesdeArchivo();

    for (auto& o : ordenes) {
        if (o.id == id) return o;
    }

    return Orden();
}

int totalMesas = 20;

void initOrderManager() {
    totalMesas = 20;
}

int getNumberTables() {
    return totalMesas;
}

void updateNumberTables(int numberTables) {
    totalMesas = numberTables;
}

int getTotalMesas() {
    return totalMesas;
}