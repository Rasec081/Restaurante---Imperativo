//
// Created by jimen on 15/3/2026.
//

#ifndef IMPERATIVO_PRODUCT_MANAGER_H
#define IMPERATIVO_PRODUCT_MANAGER_H
#include <string>
#include <vector>
#include "../shared/models.h"

using namespace std;

extern vector<Producto> listaProductos;

vector<Producto> crearProducto(string nombre, float precio);
void actualizarProducto(string nombre, string nuevoNombre);
void actualizarProducto(string nombre, float precio);
vector<Producto> getProductos();
void eliminarProducto(string nombre);
bool existeProducto(string nombre);
Producto buscarProducto(string nombre);
void addProducts();

#endif //IMPERATIVO_PRODUCT_MANAGER_H