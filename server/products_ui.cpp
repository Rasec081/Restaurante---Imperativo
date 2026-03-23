#include <iostream>
#include "products_ui.h"
#include "../shared/models.h"
#include "product_manager.h"
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

void mostrarProducto(const Producto producto) {
    cout
        << producto.nombre
        << " - Precio: "
        << producto.precio
        << endl;
}

void mostrarProductos(const vector<Producto>& productos) {

    cout << endl;
    cout << endl;
    cout << "====================================================== TABLA DE PRODUCTOS =================================================" << endl;
    cout << "===========================================================================================================================" << endl;
    cout << left << setw(10) << "#"
         << setw(40) << "Nombre"
         << right << setw(20) << "Precio" << endl;
    cout << "====================================================== ================= ==================================================" << endl;
    cout << endl;

    int index = 1;
    for (const auto& producto : productos) {
        cout << left << setw(10) << index
             << setw(40) << producto.nombre
             << right << setw(20) << fixed << setprecision(2) << producto.precio
             << endl;
        index++;
    }

    cout << "====================================================== ================= ==================================================" << endl;
    cout << endl;
}

void opcionAgregarProductos() {
    int opcion = 0;
    Producto p;

    while (opcion != 1 && opcion != 2) {

        vector<Producto> productos = getProductos();
        limpiar();

        cout << "\n==================================================== AGREGAR PRODUCTO =================================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Se le va a mostrar el listado de productos guardados antes de poder registrar un producto." << endl;
        esperar();
        mostrarProductos(productos);

        string nombreProducto;
        float precio;

        cout << endl;
        cout << "1. Nombre del producto: ";
        cin >> nombreProducto;
        cout << endl;
        cout << "2. Precio del producto: ";
        cin >> precio;
        cout << endl;

        p.nombre = nombreProducto;
        p.precio = precio;

        mostrarProducto(p);
        esperar();

        if (existeProducto(nombreProducto)) {
            cout << "(!) (!) ESTE PRODUCTO YA EXISTE (!) (!)." << endl;
            cout << "Se redirigirá automáticamente hacia el menú de gestionar. " << endl;
            break;
        }

        cout << "====================================================== =============== ==================================================" << endl;
        cout << "(?) Qué desea hacer con el producto creado?" << endl;
        cout << "1. Guardar y salir." << endl;
        cout << "2. No guardar y salir." << endl;
        cout << "3. Guardar y crear otro producto." << endl;
        cout << "4. No guardar y crear otro producto." << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;

        if (opcion == 3) {
            crearProducto(p.nombre, p.precio);
        }
    }

    if (opcion == 1) {
        crearProducto(p.nombre, p.precio);
    }

    cout << endl;
    cout << "====================================================== =============== ==================================================" << endl;
}

void opcionConsultarProductos() {
    vector<Producto> productos = getProductos();
    mostrarProductos(productos);
    esperar();
    limpiar();
}

bool menuNoExisteProducto() {
    int opcionError = 0;

    while (opcionError != 2) {
        cout << "El nombre digitado no corresponde a ningún producto." << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "(?) Qué desea hacer?" << endl;
        cout << "1. Volver a intentar." << endl;
        cout << "2. Salir" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Seleccione una opción:";
        cin >> opcionError;

        switch (opcionError) {
            case 1:
                return true;
            case 2:
                return false;
            default:
                cout << "Opcion invalida\n";
                break;
        }
    }

    return false;
}

void opcionActualizarProductos() {
    int opcion = 0;
    string nombreGuardado;
    float precioGuardado;

    while (opcion != 1 && opcion != 2) {

        vector<Producto> productos = getProductos();
        limpiar();

        cout << "\n==================================================== ACTUALIZAR PRODUCTO =================================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Se le va a mostrar el listado de productos guardados antes de poder actualizar un producto." << endl;
        esperar();
        mostrarProductos(productos);

        string nombreProducto;
        float precio;

        cout << "1. Indique el nombre de un producto para actualizarlo:";
        cin >> nombreProducto;

        if (existeProducto(nombreProducto) == false) {
            if (menuNoExisteProducto() == false) {
                break;
            }
        } else {
            Producto productoEncontrado = buscarProducto(nombreProducto);
            mostrarProducto(productoEncontrado);
            esperar();

            cout << " 2. Indique el precio del producto a actualizar: ";
            cin >> precio;

            nombreGuardado = nombreProducto;
            precioGuardado = precio;

            cout << "====================================================== =============== ==================================================" << endl;
            cout << "(?) Qué desea hacer con el producto actualizado?" << endl;
            cout << "1. Guardar y salir." << endl;
            cout << "2. No guardar y salir." << endl;
            cout << "3. Guardar y actualizar otro producto." << endl;
            cout << "4. No guardar y actualizar otro producto." << endl;
            cout << "====================================================== =============== ==================================================" << endl;
            cout << "Selecciona una opción: ";
            cin >> opcion;

            if (opcion == 3) {
                actualizarProducto(nombreGuardado, precioGuardado);
                cout << " (!) (!) Actualización exitosa! " << endl;
            }
        }
    }

    if (opcion == 1) {
        actualizarProducto(nombreGuardado, precioGuardado);
        cout << " (!) (!) Actualización exitosa! " << endl;
    }

    cout << endl;
    cout << "====================================================== =============== ==================================================" << endl;
}

void opcionEliminarProducto() {
    int opcion = 0;
    string nombreGuardado;

    while (opcion != 1 && opcion != 2) {

        vector<Producto> productos = getProductos();
        limpiar();

        cout << "\n==================================================== ELIMINAR PRODUCTO =================================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "Se le va a mostrar el listado de productos guardados antes de poder eliminar un producto." << endl;
        esperar();
        mostrarProductos(productos);

        string nombreProducto;
        cout << "1. Indique el nombre de un producto para eliminarlo:";
        cin >> nombreProducto;

        if (existeProducto(nombreProducto) == false) {
            if (menuNoExisteProducto() == false) {
                break;
            }
        } else {
            Producto productoEncontrado = buscarProducto(nombreProducto);
            mostrarProducto(productoEncontrado);
            esperar();

            nombreGuardado = nombreProducto;

            cout << "====================================================== =============== ==================================================" << endl;
            cout << "(?) Qué desea hacer con el producto que desea eliminar?" << endl;
            cout << "1. Eliminar y salir." << endl;
            cout << "2. No eliminar y salir." << endl;
            cout << "3. Eliminar producto y eliminar otro producto." << endl;
            cout << "4. No eliminar y eliminar otro producto." << endl;
            cout << "====================================================== =============== ==================================================" << endl;
            cout << "Selecciona una opción: ";
            cin >> opcion;

            if (opcion == 3) {
                eliminarProducto(nombreGuardado);
                cout << " (!) (!) Eliminación exitosa! " << endl;
            }
        }
    }

    if (opcion == 1) {
        eliminarProducto(nombreGuardado);
        cout << " (!) (!) Eliminación exitosa! " << endl;
    }

    cout << endl;
    cout << "====================================================== =============== ==================================================" << endl;
}

void menuGestionarProductos() {
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
                limpiar();
                opcionAgregarProductos();
                break;
            case 2:
                limpiar();
                opcionConsultarProductos();
                break;
            case 3:
                limpiar();
                opcionActualizarProductos();
                break;
            case 4:
                limpiar();
                opcionEliminarProducto();
                break;
            default:
                cout << "Opcion invalida\n";
                esperar();
        }
    }
}