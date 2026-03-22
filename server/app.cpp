#include "products_ui.h"
#include <iostream>

using namespace std;

void menuPrincipal() {
    // 1. Para mostrar lo productos, ordnees, etc
    int opcion = 0;

    while (opcion != 4) {

        cout << "\n====================================================== SISTEMA MESEROS ==================================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "1. Administrar Productos\n";
        cout << "2. Administrar Ordenes\n";
        cout << "3. Salir\n";
        cout << "====================================================== =============== ==================================================" << endl;

        cout << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                limpiar();
                menuGestionarProductos();
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