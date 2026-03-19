#pragma once
#include <vector>
#include "../shared/models.h"
using namespace std;

bool existeProducto(const vector<ProductoEscogido>& productosEscogidos, string nombre);
Producto* buscarProducto(vector<Producto>& productos, string nombre);
void actualizarProductoEscogido(vector<ProductoEscogido>& productosEscogidos, string nombre, int cantidad);
void insertarProductoEscogido(vector<ProductoEscogido>& productosEscogidos, string nombre, int cantidad);