#pragma once
#include <vector>
#include "../shared/models.h"
using namespace std;

void esperar();
void limpiar();
void mostrarProductosEscogidos(const vector<ProductoEscogido>& productosEscogidos);
void mostrarProducto(const Producto producto);
void mostrarProductos(const vector<Producto>& productos);
vector<ProductoEscogido> escogerProductos(vector<ProductoEscogido>& productosEscogidos);
void menuCrearOrden();
void menuPrincipal();