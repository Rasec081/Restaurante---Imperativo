#include "products_ui.h"
#include "orders_ui.h"
#include "table_numbers_ui.h"
#include <iostream>

#include "order_manager.h"
#include "product_manager.h"

using namespace std;

void menuPrincipal() {
    // 1. Para mostrar lo productos, ordnees, etc
    int opcion = 0;
    ProductManager pm;
    OrderManager om;

    while (opcion != 4) {

        cout << "\n====================================================== SISTEMA MESEROS ==================================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "1. Administrar Productos.\n";
        cout << "2. Administrar Ordenes.\n";
        cout << "3. Configurar # de mesas.\n";
        cout << "4. Salir\n";
        cout << "====================================================== =============== ==================================================" << endl;

        cout << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                limpiar();
                menuGestionarProductos(pm);
                break;
            case 2:
                limpiar();
                menuGestionarOrdenes(om);
                break;
            case 3:
                limpiar();
                menuGestionarNumeroMesas(om);
                break;
            default:
                cout << "Opcion invalida\n";
                esperar();
        }

    }
}


int main() {

    menuPrincipal();
    return 0;
}