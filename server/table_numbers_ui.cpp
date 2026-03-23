#include <iostream>
#include "products_ui.h"
#include "order_manager.h"

using namespace std;

void opcionConsultarNumeroMesa() {

    cout << "\n===================================================== NÚMERO DE MESA ==================================================" << endl;
    cout << "====================================================== =============== ==================================================" << endl;
    cout << getNumberTables();
    cout << endl;
    cout << "====================================================== =============== ==================================================" << endl;
    esperar();
}

void opcionActualizarNumeroMesas() {

    // - Opcion para consultar ordenes
    int opcion = 0;

    while (opcion != 1 and opcion != 2) {
        limpiar();

        cout << "\n=============================================== ACTUALIZAR NÚMERO DE MESAS ============================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Se le va a mostrar el listado de número de mesas antes de poder actualizar el valor." << endl;
        esperar();
        opcionConsultarNumeroMesa();

        int numeroMesas;

        cout << endl;
        cout << "1. Número de mesas a actualizar: ";
        cin >> numeroMesas;
        cout << endl;


        cout << "====================================================== =============== ==================================================" << endl;
        cout << "(?) Qué desea hacer con la número de mesas actualizada?" << endl;
        cout << "1. Actualizar y salir." << endl;
        cout << "2. No actualizar y salir." << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            updateNumberTables(numeroMesas);
        }
    }

    cout << endl;
    cout << "====================================================== =============== ==================================================" << endl;

}

void menuGestionarNumeroMesas() {
    // - Menu para gestionar el numero de mesas

    int opcion = 0;

    while (opcion != 3) {

        cout << "\n=============================================== ADMINISTRAR NÚMERO DE MESAS ===========================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "1. Actualizar número de mesas. \n";
        cout << "2. Consultar número de mesas.\n";
        cout << "3. Salir.\n";
        cout << "====================================================== =============== ==================================================" << endl;

        cout << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                limpiar();
                opcionActualizarNumeroMesas();
                break;
            case 2:
                limpiar();
                opcionConsultarNumeroMesa();
                break;
            case 3:
                limpiar();
                break;
            default:
                cout << "Opcion invalida\n";
                esperar();
        }
    }
}