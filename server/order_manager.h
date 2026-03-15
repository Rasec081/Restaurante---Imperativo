#ifndef IMPERATIVO_ORDER_MANAGER_H
#define IMPERATIVO_ORDER_MANAGER_H

#include <string>
#include <vector>

using namespace std;

//**** STRUCTS ****//

struct OrderItem { //struc temporal en lo que recibo el .h de Luis y Jime, ya despues solo hago un inclde del h de ellos
    string producto;
    int cantidad;
};

struct Order {
    int order_id;
    int mesa;
    vector<OrderItem> items;
    bool completada; //i no completa y 1 es completada
};

class OrderManager {

private:

    vector<Order> orders; //todas las ordenes que va ahaber en la cocina
    int nextId;

public:

    OrderManager();

    void addOrder(int mesa, vector<OrderItem> items);

    void deleteOrder(int order_id);

    void updateOrder(int order_id, vector<OrderItem> items);

    void completeOrder(int order_id);

    vector<Order> getOrders();

};

#endif