#include <iostream>
#include "products_ui.h"
#include "product_manager.h"
#include "../shared/models.h"

#include <limits>
#include <iomanip> // setw, left, right

using namespace std;

void esperar() {
    cout << "Presiona Enter para continuar...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void limpiar() {
    for(int i = 0; i < 50; i++) cout << endl;
}

void mostrarProductos(const vector<Producto>& productos) {

    cout << "====================================================== TABLA DE PRODUCTOS =================================================" << endl;
    cout << "===========================================================================================================================" << endl;
    cout << left << setw(10) << "#"
         << setw(40) << "Nombre"
         << right << setw(20) << "Precio" << endl;
    cout << "====================================================== ================= ==================================================" << endl;

    int index = 1;
    for (const auto& producto : productos) {
        cout << left << setw(10) << index
             << setw(40) << producto.nombre
             << right << setw(20) << fixed << setprecision(2) << producto.precio
             << endl;
        index++;
    }

    cout << "====================================================== ================= ==================================================" << endl;

}

void opcionAgregarProductos() {
    // -Menu para agregar productos
    int opcion = 0;

    // 1. Obtener los productos
    vector<Producto> productos;
    //productos = pedirProductos();
    Producto p;
    p.nombre = "Pizza";
    p.precio = 10;
    Producto p2;
    p2.nombre = "Pasta";
    p2.precio = 5;
    productos.push_back(p);
    productos.push_back(p2);

    cout << "\n==================================================== AGREGAR PRODUCTO =================================================" << endl;
    cout << "====================================================== =============== ==================================================" << endl;
    cout << "Se le va a mostrar el listado de productos guardados antes de poder registrar un producto." << endl;
    esperar();
    mostrarProductos(productos);
    cout << endl;
    cout << "====================================================== =============== ==================================================" << endl;

    string nombreProducto;
    float precio;

    cout << endl;
    cout << "1. Nombre del producto: ";
    cin >> nombreProducto;
    cout << endl;
    cout << "2. Precio del producto: ";
    cin >> precio;
    cout << endl;
    Producto p3 = {nombreProducto,precio};

    ProductManager pm;

    pm.crearProducto(p.nombre, p.precio);

    auto productos2 = pm.getProductos();
    mostrarProductos(productos2);

}

void menuGestionarProductos() {
    // - Menu para gestionar los productos del restaurante
    int opcion = 0;

    while (opcion != 5) {

        cout << "\n================================================== ADMINISTRAR PRODUCTOS ===============================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "1. Crear productos\n";
        cout << "2. Consultar productos\n";
        cout << "3. Actualizar productos\n";
        cout << "4. Eliminar productos\n";
        cout << "5. Salir\n";
        cout << "====================================================== =============== ==================================================" << endl;

        cout << endl;
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                opcionAgregarProductos();
                break;
            default:
                cout << "Opcion invalida\n";
                esperar();
        }
    }
}

