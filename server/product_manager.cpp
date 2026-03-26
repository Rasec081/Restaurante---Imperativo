#include "product_manager.h"
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

string FILE_PATH = "productos.json";

vector<Producto> leerProductosDesdeArchivo() {
    vector<Producto> productos;

    ifstream file(FILE_PATH);
    if (!file.is_open()) {
        return productos;
    }

    json j;
    file >> j;

    for (auto& item : j) {
        Producto p;
        p.nombre = item["nombre"];
        p.precio = item["precio"];
        productos.push_back(p);
    }

    return productos;
}

void guardarProductosEnArchivo(vector<Producto> productos) {
    json j = json::array();

    for (auto& p : productos) {
        j.push_back({
            {"nombre", p.nombre},
            {"precio", p.precio}
        });
    }

    ofstream file(FILE_PATH);
    file << j.dump(4);
}

vector<Producto> crearProducto(string nombre, float precio) {
    vector<Producto> productos = leerProductosDesdeArchivo();

    Producto nuevo;
    nuevo.nombre = nombre;
    nuevo.precio = precio;

    productos.push_back(nuevo);

    guardarProductosEnArchivo(productos);

    return productos;
}

vector<Producto> getProductos() {
    return leerProductosDesdeArchivo();
}

void actualizarProducto(string nombre, string nuevoNombre) {
    vector<Producto> productos = leerProductosDesdeArchivo();

    for (auto& p : productos) {
        if (p.nombre == nombre) {
            p.nombre = nuevoNombre;
            break;
        }
    }

    guardarProductosEnArchivo(productos);
}

void actualizarProducto(string nombre, float precio) {
    vector<Producto> productos = leerProductosDesdeArchivo();

    for (auto& p : productos) {
        if (p.nombre == nombre) {
            p.precio = precio;
            break;
        }
    }

    guardarProductosEnArchivo(productos);
}

void eliminarProducto(string nombre) {
    vector<Producto> productos = leerProductosDesdeArchivo();

    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].nombre == nombre) {
            productos.erase(productos.begin() + i);
            break;
        }
    }

    guardarProductosEnArchivo(productos);
}

bool existeProducto(string nombre) {
    vector<Producto> productos = leerProductosDesdeArchivo();

    for (auto& p : productos) {
        if (p.nombre == nombre) {
            return true;
        }
    }
    return false;
}

Producto buscarProducto(string nombre) {
    vector<Producto> productos = leerProductosDesdeArchivo();

    for (auto& p : productos) {
        if (p.nombre == nombre) {
            return p;
        }
    }

    return {"", 0};
}

void addProducts() {
    vector<Producto> productos = leerProductosDesdeArchivo();

    if (!productos.empty()) return;

    productos = {
        {"Pizza", 3500},
        {"Hamburguesa", 4000},
        {"Refresco", 1000},
        {"Tacos al pastor", 2500},
        {"Enchiladas verdes", 2800},
        {"Ceviche", 3200},
        {"Paella", 4500},
        {"Sushi", 3800},
        {"Milanesa", 3000},
        {"Flan napolitano", 1500}
    };

    guardarProductosEnArchivo(productos);
}