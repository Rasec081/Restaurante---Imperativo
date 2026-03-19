//
// Created by gambo on 19/3/2026.
//

#ifndef IMPERATIVO_STRUCTS_H
#define IMPERATIVO_STRUCTS_H

#define MSG_ENVIAR_ORDEN        1
#define MSG_EDITAR_ORDEN        2
#define MSG_BORRAR_ORDEN        3
#define MSG_VER_ORDENES         4
#define MSG_ENVIAR_ORDENES_SV   5
#define MSG_ENVIAR_PRODUCTO     6
#define MSG_VER_PRODUCTO        7
#define MSG_ENVIAR_PRODUCTOS_SV 8
#define MSG_EDITAR_PRODUCTO     9
#define MSG_BORRAR_PRODUCTO     10

#include ".../models.h"



struct editarOrden {
    int id; // cuando se crea desde la consola cliente, se pone como 0.
    vector<ProductoEscogido> orden;
};

struct borrarOrden {
    int id;
};

struct enviarOrdenesSv {
    vector<crearOrden> ordenes;
};

struct enviarProducto {
    ProductoEscogido producto;
};

struct enviarProductosSV {
    int id; // cuando se crea desde la consola cliente, se pone como 0.
    vector<ProductoEscogido> productos;
};

struct editarProducto {
    int id; // cuando se crea desde la consola cliente, se pone como 0.
    vector<ProductoEscogido> producto;
};

struct borrarProducto {
    int id; // cuando se crea desde la consola cliente, se pone como 0.
};

struct Mensaje {
    int tipo;

    union {
        EnviarOrden crearOrden;
        EditarOrden editarOrden;
        BorrarOrden borrarOrden;
        EnviarOrdenesSv enviarOrdenesSv;
        EnviarProducto enviarProducto;
        EnviarProductosSv enviarProductosSv;
        EditarProducto editarProducto;
        BorrarProducto borrarProducto;
    };
};

#endif //IMPERATIVO_STRUCTS_H
