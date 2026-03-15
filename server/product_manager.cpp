//
// Created by jimen on 15/3/2026.
//

#include "product_manager.h"
#include <string>
#include <iomanip>
using namespace std;

vector<Producto> ProductManager::crearProducto(string nombre, float precio) {

    Producto nuevoProducto;

    cantidad++;
    nuevoProducto.id = cantidad;
    nuevoProducto.nombre = nombre;
    nuevoProducto.precio = precio;

    listaProductos.push_back(nuevoProducto);

    return listaProductos;
}

void ProductManager::actualizarProducto(int id, string nombre, float precio) {

    for (int i = 0; i < listaProductos.size(); i++) {

        if (listaProductos[i].id == id) {

            listaProductos[i].nombre = nombre;
            listaProductos[i].precio = precio;
            break;
        }
    }
}

vector<Producto> ProductManager::getProductos() {

    return listaProductos;
}

void ProductManager::eliminarProducto(int id) {

    for (int i = 0; i < listaProductos.size(); i++) {

        if (listaProductos[i].id == id) {

            listaProductos.erase(listaProductos.begin() + i);
            break;
        }
    }
}