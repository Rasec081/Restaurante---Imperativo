#ifndef MODELS_H
#define MODELS_H

#include <string>

struct Orden {
    int id;
    int mesa;

};

struct Producto {
    std::string nombre;
    float precio;
};

struct ProductoEscogido {
    std::string nombre;
    int cantidad;
};

#endif