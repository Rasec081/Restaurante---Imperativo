#ifndef IMPERATIVO_CLIENT_LOGIC_H
#define IMPERATIVO_CLIENT_LOGIC_H

#include <vector>
#include "client_logic.h"
#include "../shared/models.h"
using namespace std;

bool existeProducto(const vector<ProductoEscogido>& productosEscogidos, string nombre);
Producto* buscarProducto(vector<Producto>& productos, string nombre);
void actualizarProductoEscogido(vector<ProductoEscogido>& productosEscogidos, string nombre, int cantidad);
void insertarProductoEscogido(vector<ProductoEscogido>& productosEscogidos, string nombre, int cantidad);

#endif //IMPERATIVO_CLIENT_LOGIC_H