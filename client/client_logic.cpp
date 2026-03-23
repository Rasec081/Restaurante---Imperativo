#include <cstdlib>
#include <iostream>
#include <vector>
#include "../shared/models.h"
#include "network_client.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

bool existeProducto(const vector<ProductoEscogido>& productosEscogidos, string nombre) {
    // - Funcion que valida si el producto existe en el hashmap

    for (auto producto: productosEscogidos) {

        if (producto.nombre == nombre) {
            return true;
        }
    }

    return false;
}

Producto* buscarProducto(vector<Producto>& productos, string nombre) {

    for (auto& producto : productos) {
        if (producto.nombre == nombre) {
            return &producto;
        }
    }

    return nullptr;
}

void actualizarProductoEscogido(vector<ProductoEscogido>& productosEscogidos, string nombre, int cantidad) {

    for (auto& productoEscogido: productosEscogidos) {
        if (productoEscogido.nombre == nombre) {
            productoEscogido.cantidad = cantidad;
        }
    }
}

void insertarProductoEscogido(vector<ProductoEscogido>& productosEscogidos, string nombre, int cantidad) {
    ProductoEscogido pe;
    pe.nombre = nombre;
    pe.cantidad = cantidad;
    productosEscogidos.push_back(pe);
}

vector<json> obtenerOrdenes() {
    json request;
    request["type"] = "GET_ORDERS";

    json response = sendJSON(request);

    vector<json> orders;

    if (!response.is_object()) {
        cout << "Respuesta inválida del servidor\n";
        return orders;
    }

    if (!response.contains("orders") || !response["orders"].is_array()) {
        return orders;
    }

    for (auto& o : response["orders"]) {
        if (o.is_object()) {
            orders.push_back(o);
        }
    }

    return orders;
}

vector<ProductoEscogido> obtenerDetalleOrden(int id) {

    json request;
    request["type"] = "GET_ORDER_DETAIL";
    request["id"] = id;

    json response = sendJSON(request);

    vector<ProductoEscogido> productos;

    if (!response.is_object()) return productos;

    if (response["status"] == "OK") {

        for (auto& p : response["order"]["productos"]) {
            ProductoEscogido pe;
            pe.nombre = p["nombre"].get<string>();
            pe.cantidad = p["cantidad"].get<int>();
            productos.push_back(pe);
        }
    }

    return productos;
}

void eliminarProductoEscogido(vector<ProductoEscogido>& productos, string nombre) {

    for (int i = 0; i < productos.size(); i++) {

        if (productos[i].nombre == nombre) {
            productos.erase(productos.begin() + i);
            break;
        }
    }
}

int obtenerMaxMesas() {
    json request;
    request["type"] = "GET_MAX_MESAS";

    json response = sendJSON(request);
    return response["max_mesas"].get<int>();
}

bool validarMesa(int mesaEscogida) {
    int maxMesas = obtenerMaxMesas(); //esto es un json, hay que hacerlo int
    return mesaEscogida >= 1 && mesaEscogida <= maxMesas;
}