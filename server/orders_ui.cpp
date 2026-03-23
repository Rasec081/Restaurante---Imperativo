#include <iostream>
#include "products_ui.h"
#include "../shared/models.h"
#include "order_manager.h"
#include <limits>
#include <iomanip> // setw, left, right

using namespace std;


void mostrarOrdenes(const vector<Orden>& ordenes) {

    cout << endl;
    cout << endl;
    cout << "====================================================== TABLA DE ORDENES =================================================" << endl;
    cout << "===========================================================================================================================" << endl;
    cout << left << setw(10) << "#"
         << setw(25) << "Número Mesa"
        << left << setw(15) << "Estado"
        << right << setw(20) << "Producto Solicitado (Cantidad)" << endl;
    cout << "====================================================== ================= ==================================================" << endl;
    cout << endl;

    for (const auto& orden : ordenes) {
        string estadoString;
        if (orden.estado == true) {
            estadoString = "Completa";
        }else {
            estadoString = "Incompleta";
        }


        cout    << left << setw(10) << orden.id
                << setw(24) << orden.numeroMesa
                << setw(25) << estadoString
                << endl;

        // ahora recorrer los productos:
        for (const auto& producto : orden.productos) {
            cout << setw(49) << ""  // desplaza hasta la columna de productos
                 << producto.nombre << " (" << producto.cantidad << ")"
                 << endl;
        }
    }


    cout << "====================================================== ================= ==================================================" << endl;
    cout << endl;
}

void opcionConsultarOrdenesPendientes(OrderManager &om) {
    // - Opcion para consultar ordenes
    mostrarOrdenes(om.getPendingOrders());
    esperar();
    limpiar();
}

void opcionConsultarOrdenes(OrderManager &om) {
    // - Opcion para consultar ordenes

    Orden orden;
    orden.id = 1;
    orden.numeroMesa = 24;
    vector<ProductoEscogido> prodEscogidos;
    prodEscogidos.push_back({"Pizza", 10});
    prodEscogidos.push_back({"Pollo Plancha", 1});
    prodEscogidos.push_back({"Coca Cola", 2});
    orden.productos = prodEscogidos;

    Orden orden2;
    orden2.id = 2;
    orden2.numeroMesa = 33;
    vector<ProductoEscogido> prodEscogidos2;
    prodEscogidos2.push_back({"Pizza2", 10});
    prodEscogidos2.push_back({"Pollo Plancha2", 1});
    prodEscogidos2.push_back({"Coca Cola2", 2});
    orden2.productos = prodEscogidos2;

    om.addOrder(orden);
    om.addOrder(orden2);

    mostrarOrdenes(om.getOrders());
    esperar();
    limpiar();
}

void opcionCompletarOrden(OrderManager &om) {
    // - Opcion para consultar ordenes
    int opcion = 0;

    while (opcion != 1 and opcion != 2) {
        limpiar();

        cout << "\n==================================================== COMPLETAR ORDEN ==================================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Se le va a mostrar el listado de ordenes incompletas antes de poder completar una orden." << endl;
        esperar();
        mostrarOrdenes(om.getPendingOrders());

        int idOrden;

        cout << endl;
        cout << "1. # de orden a completar: ";
        cin >> idOrden;
        cout << endl;

        esperar();

        if (om.orderExists(idOrden) == false) {
            cout << "(!) (!) LA ORDEN SELECCIONADA NO EXISTE (!) (!)." << endl;
            cout << "Se redirigirá automáticamente hacia el menú de gestionar. " << endl;
            break;
        }

        cout << "====================================================== =============== ==================================================" << endl;
        cout << "(?) Qué desea hacer con la orden seleccionada?" << endl;
        cout << "1. Completar y salir." << endl;
        cout << "2. No completar y salir." << endl;
        cout << "3. Completar y completar otro producto." << endl;
        cout << "4. No completar y completar otro producto." << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;

        if (opcion == 3 or opcion == 1) {
            om.completeOrder(idOrden);
        }
    }

    cout << endl;
    cout << "====================================================== =============== ==================================================" << endl;
}

void menuGestionarOrdenes(OrderManager &om) {
    // - Menu para gestionar las ordenes del restaurante
    int opcion = 0;

    while (opcion != 5) {

        cout << "\n================================================== ADMINISTRAR ORDENES ===============================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "1. Consultar ordenes.\n";
        cout << "2. Consultar ordenes pendientes.\n";
        cout << "3. Marcar orden como completada.\n";
        cout << "4. Salir\n";
        cout << "====================================================== =============== ==================================================" << endl;

        cout << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                limpiar();
                opcionConsultarOrdenes(om);
                break;
            case 2:
                limpiar();
                opcionConsultarOrdenesPendientes(om);
                break;
            case 3:
                limpiar();
                opcionCompletarOrden(om);
                break;
            case 4:
                limpiar();
                break;
            default:
                cout << "Opcion invalida\n";
                esperar();
        }
    }
}