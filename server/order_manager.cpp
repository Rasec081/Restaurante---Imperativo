//
// Created by Daniel on 15/3/2026.
//

#include "order_manager.h"
#include <vector>

using namespace std;

OrderManager::OrderManager() {
    nextId = 1;
}

void OrderManager::addOrder(int mesa, vector<ProductoEscogido> productos) {

    Orden nuevaOrden;
    nuevaOrden.id = nextId++;
    nuevaOrden.mesa = mesa;
    //si Luis le agrega el vector aca va productos
    orders.push_back(nuevaOrden);

}

void OrderManager::deleteOrder(int order_id) { //aca va opcional porque no se como el cliente va a saber el id,
                                                //tal vez sea mejor buscar por numero de mesa

    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].id == order_id) {
            orders.erase(orders.begin() + i);
            return;
        }
    }
}

void OrderManager::updateOrder(int order_id, vector<ProductoEscogido> productos) {

    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].id == order_id) {

            // seria con el vector d ela estructura
            return;
        }
    }
}

void OrderManager::completeOrder(int order_id) {

    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].id == order_id) {

            // si Orden tuviera estado:
            // orders[i].completada = true;

            return;
        }
    }
}

vector<Orden> OrderManager::getOrders() {
    return orders;
}