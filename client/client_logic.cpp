#include <cstdlib>
#include <iostream>
#include <vector>
#include "../shared/models.h"

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