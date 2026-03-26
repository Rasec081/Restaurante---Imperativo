//
// Created by gambo on 22/3/2026.
//
#include <unistd.h>
#include <sys/socket.h>
#include <iostream>

#include "network_server.h"
#include "order_manager.h"
#include "product_manager.h"

#include "products_ui.h"
#include "orders_ui.h"
#include "table_numbers_ui.h"


using namespace std;

void menuPrincipal() {
    int opcion = 0;

    while (opcion != 4) {

        cout << "\n================ SISTEMA MESEROS ================\n";
        cout << "1. Administrar Productos\n";
        cout << "2. Administrar Ordenes\n";
        cout << "3. Configurar # de mesas\n";
        cout << "4. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                limpiar();
                menuGestionarProductos();
                break;
            case 2:
                limpiar();
                menuGestionarOrdenes();
                break;
            case 3:
                limpiar();
                menuGestionarNumeroMesas();
                break;
            case 4:
                break;
            default:
                cout << "Opcion invalida\n";
                esperar();
        }
    }
}

int main() {
	addProducts();
    initOrderManager();

    int server_socket = createServer();

    pid_t pid = fork();

    if (pid == 0) {
        while (true) {

            int client_socket = accept(server_socket, NULL, NULL);
            if (client_socket < 0) continue;

            pid_t pid2 = fork();

            if (pid2 == 0) {
                close(server_socket);
                handleClient(client_socket);
            } else {
                close(client_socket);
            }
        }
    } else {
        menuPrincipal();
    }

    return 0;
}