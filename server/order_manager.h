//
// Created by Daniel on 15/3/2026.
//

#ifndef IMPERATIVO_ORDER_MANAGER_H
#define IMPERATIVO_ORDER_MANAGER_H

#include "../shared/models.h"
#include <vector>

using namespace std;

class OrderManager {

private:

    vector<Orden> orders;   // todas las órdenes que llegan a la cocina
    int nextId;
    int totalMesas;

public:

    OrderManager();

    void addOrder(Orden orden);

    void deleteOrder(int order_id);

    void updateOrder(int order_id, vector<ProductoEscogido> productos);

    void completeOrder(int order_id);

    vector<Orden> getOrders();

    vector<Orden> getPendingOrders();

    bool orderExists(int orderId);

    int getNumberTables();

    void updateNumberTables(int numberTables);

};

#endif