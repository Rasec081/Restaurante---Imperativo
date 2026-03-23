#pragma once
#include <vector>
#include "../shared/models.h"
#include "product_manager.h"
using namespace std;

void esperar();
void limpiar();
void mostrarProducto(Producto producto);
void mostrarProductos(const vector<Producto>& productos);
void opcionAgregarProductos();
void menuGestionarProductos();
bool menuNoExisteProducto();