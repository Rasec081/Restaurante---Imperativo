//
// Created by jimen on 15/3/2026.
//

#include "product_manager.h"
#include <string>
#include <iomanip>
using namespace std;
vector<Producto> listaProductos;

vector<Producto> crearProducto(string nombre, float precio) {

    Producto nuevoProducto;
    nuevoProducto.nombre = nombre;
    nuevoProducto.precio = precio;

    listaProductos.push_back(nuevoProducto);

    return listaProductos;
}


void actualizarProducto(string nombre, string nuevoNombre) {

    for (int i = 0; i < listaProductos.size(); i++) {

        if (listaProductos[i].nombre == nombre) {
            listaProductos[i].nombre = nuevoNombre;
            break;
        }
    }
}

void actualizarProducto(string nombre, float precio) {

    for (int i = 0; i < listaProductos.size(); i++) {

        if (listaProductos[i].nombre == nombre) {
            listaProductos[i].precio = precio;
            break;
        }
    }
}

vector<Producto> getProductos() {

    return listaProductos;
}

void eliminarProducto(string nombre) {

    for (int i = 0; i < listaProductos.size(); i++) {

        if (listaProductos[i].nombre == nombre) {

            listaProductos.erase(listaProductos.begin() + i);
            break;
        }
    }
}

void addProducts() {
    listaProductos.push_back({"Pizza", 3500});
    listaProductos.push_back({"Hamburguesa", 4000});
    listaProductos.push_back({"Refresco", 1000});
    listaProductos.push_back({"Tacos al pastor", 2500});
    listaProductos.push_back({"Enchiladas verdes", 2800});
    listaProductos.push_back({"Ceviche", 3200});
    listaProductos.push_back({"Paella", 4500});
    listaProductos.push_back({"Sushi", 3800});
    listaProductos.push_back({"Milanesa", 3000});
    listaProductos.push_back({"Flan napolitano", 1500});
