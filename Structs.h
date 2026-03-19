//
// Created by gambo on 19/3/2026.
//

#ifndef IMPERATIVO_STRUCTS_H
#define IMPERATIVO_STRUCTS_H

#define MSG_ENVIAR_ORDEN        1
#define MSG_EDITAR_ORDEN        2
#define MSG_BORRAR_ORDEN        3
#define MSG_VER_ORDENES         4
#define MSG_ENVIAR_PRODUCTO     5
#define MSG_CONSULTAR_PRODUCTO  6
#define MSG_EDITAR_PRODUCTO     7
#define MSG_BORRAR_PRODUCTO     8

#endif //IMPERATIVO_STRUCTS_H


struct Mensaje {
    int tipo;

    union {
        EnviarOrden crearOrden;
        EditarOrden editarOrden;
        BorrarOrden borrarOrden;
        VerOrdenes verOrdenes;
        EnviarProducto enviarProducto;
        ConsultarProducto consultarProducto;
        EditarProducto editarProducto;
        BorrarProducto borrarProducto;
    };
};
