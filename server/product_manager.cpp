//
// Created by jimen on 15/3/2026.
//

#include "product_manager.h"
#include <string>
#include <iomanip>
using namespace std;
ProductManager::ProductManager() {}
vector<Producto> ProductManager::crearProducto(string nombre, float precio) {

    Producto nuevoProducto;
    nuevoProducto.nombre = nombre;
    nuevoProducto.precio = precio;

    listaProductos.push_back(nuevoProducto);

    return listaProductos;
}

void ProductManager::actualizarProducto(string nombre, string nuevoNombre, float precio) {

    for (int i = 0; i < listaProductos.size(); i++) {

        if (listaProductos[i].nombre == nombre) {
            listaProductos[i].nombre = nuevoNombre;
            listaProductos[i].precio = precio;
            break;
        }
    }
}


vector<Producto> ProductManager::getProductos() {

    return listaProductos;
}

void ProductManager::eliminarProducto(string nombre) {

    for (int i = 0; i < listaProductos.size(); i++) {

        if (listaProductos[i].nombre == nombre) {

            listaProductos.erase(listaProductos.begin() + i);
            break;
        }
    }
}