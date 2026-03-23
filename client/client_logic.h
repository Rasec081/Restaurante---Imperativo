#ifndef IMPERATIVO_CLIENT_LOGIC_H
#define IMPERATIVO_CLIENT_LOGIC_H

#include <vector>
#include "client_logic.h"
#include "../shared/models.h"
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

bool existeProducto(const vector<ProductoEscogido>& productosEscogidos, string nombre);
Producto* buscarProducto(vector<Producto>& productos, string nombre);
void actualizarProductoEscogido(vector<ProductoEscogido>& productosEscogidos, string nombre, int cantidad);
void insertarProductoEscogido(vector<ProductoEscogido>& productosEscogidos, string nombre, int cantidad);
vector<json> obtenerOrdenes();
vector<ProductoEscogido> obtenerDetalleOrden(int id);
void eliminarProductoEscogido(vector<ProductoEscogido>& productos, string nombre);
bool validarMesa(int mesaEscogida);
#endif //IMPERATIVO_CLIENT_LOGIC_H