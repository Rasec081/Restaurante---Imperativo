#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <vector>
using namespace std;


struct Producto {
    std::string nombre;
    float precio;
};

struct ProductoEscogido {
    std::string nombre;
    int cantidad;
};

struct Orden {
    int id; // cuando se crea desde la consola cliente, se pone como 0.
    int numeroMesa;
    vector<ProductoEscogido> productos;
};

#endif