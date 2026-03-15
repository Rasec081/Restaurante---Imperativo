//
// Created by jimen on 15/3/2026.
//

#ifndef IMPERATIVO_PRODUCT_MANAGER_H
#define IMPERATIVO_PRODUCT_MANAGER_H
#include <string>
#include <vector>
using namespace std;


struct Producto {
    string nombre;
    float precio;
};

class ProductManager {

private:
    vector<Producto> listaProductos;

public:
    ProductManager();

    vector<Producto> crearProducto(string nombre, float precio);
    void actualizarProducto(string nombre, string nuevoNombre, float precio);
    vector<Producto> getProductos();
    void eliminarProducto(string nombre);
};
#endif //IMPERATIVO_PRODUCT_MANAGER_H