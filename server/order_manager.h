//
// Created by Daniel on 15/3/2026.
//

#ifndef IMPERATIVO_ORDER_MANAGER_H
#define IMPERATIVO_ORDER_MANAGER_H

#include "../shared/models.h"
#include <vector>

using namespace std;



extern vector<Orden> orders;
extern int nextId;
extern int totalMesas;



void initOrderManager();

void addOrder(Orden orden);

void deleteOrder(int order_id);

void updateOrder(int order_id, vector<ProductoEscogido> productos);

void completeOrder(int order_id);

vector<Orden> getOrders();

int getTotalMesas();

Orden getOrderById(int id);

#endif