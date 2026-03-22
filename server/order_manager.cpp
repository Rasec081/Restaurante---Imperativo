//
// Created by Daniel on 15/3/2026.
//

#include "order_manager.h"
#include <vector>

using namespace std;

vector<Orden> orders;
int nextId;
int totalMesas;

void initOrderManager() {
    nextId = 1;
    totalMesas = 20;
}

void addOrder(Orden orden) {

    orden.id = nextId++;      //e l id viene en 0 entonces le pongo uno correcto
    orden.estado = false;     //por si acso

    orders.push_back(orden);  /*aca ya estoy guartdando el id, numero de la mesa,
                                la lista de comidas y sus cantidades, y el estado
                                cada elemento del vector*/
}

void deleteOrder(int order_id) { //aca va opcional porque no se como el cliente va a saber el id,
                                                //tal vez sea mejor buscar por numero de mesa

    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].id == order_id) {
            orders.erase(orders.begin() + i);
            return;
        }
    }
}

/*
 * aca no seria mejor en vez de id tal vez poner el numero de la mesa para así
 * buscar la orden que este pendiente y ademas tenga ese mismo numero de mesa?
 *
 *
 *podria pasar los productos por referencia a pesar de ser con sockets?
 */
void updateOrder(int order_id, vector<ProductoEscogido> productos) {

    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].id == order_id) {

            // seria con el vector d ela estructura
            orders[i].productos = productos;


            return;
        }
    }
}


void completeOrder(int order_id) {
    /*
     * aca no seria mejor en vez de id tal vez poner el numero de la mesa para así
     * buscar la orden que este pendiente y ademas tenga ese mismo numero de mesa?
     * y así lo ponermos ya como completado?
     * es que sino el cliente tendria que saber el id de las oprdenes y eso no
     * tiene snetido
     */
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].id == order_id) {

            // si Orden tuviera estado:
            orders[i].estado = true;

            return;
        }
    }
}

vector<Orden> getOrders() {
    return orders;
}

int getTotalMesas() {
    return totalMesas;
}