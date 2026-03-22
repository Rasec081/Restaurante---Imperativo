#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip> // setw, left, right

#include "../shared/models.h"
#include "client_logic.h"
#include <limits>

using namespace std;

void esperar() {
    cout << "Presiona Enter para continuar...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void limpiar() {
    for(int i = 0; i < 50; i++) cout << endl;
}

void mostrarProductosEscogidos(const vector<ProductoEscogido>& productosEscogidos) {

    cout << endl;
    cout << "================================== TABLA DE PRODUCTOS ESCOGIDOS ==================================" << endl;
    cout << "==================================================================================================" << endl;

    cout << left << setw(10) << "#"
         << setw(40) << "Nombre"
         << right << setw(20) << "Cantidad" << endl;

    cout << "==================================================================================================" << endl;

    int index = 1;
    for (const auto& pEscogido : productosEscogidos) {
        cout << left << setw(10) << index
             << setw(40) << pEscogido.nombre
             << right << setw(20) << pEscogido.cantidad
             << endl;
        index++;
    }

    cout << "==================================================================================================" << endl;
    cout << endl;
}

void mostrarProducto(const Producto producto) {
    cout
        << producto.nombre
        << " - Precio: "
        << producto.precio
        << endl;
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

vector<ProductoEscogido> escogerProductos(vector<ProductoEscogido>& productosEscogidos) {
    // 1. Obtener los productos
    // 2. Se envia como parametro los productos que ya se tienen (en caso de tenerlos)
    // 3. Se agregan/modifican los productos
    // 4. Se retorna la lista modificada

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

    while (opcion != 4) {
        limpiar();
        cout << "\n====================================================== ESCOGER PRODUCTOS ==================================================" << endl;
        cout << "====================================================== ================= ==================================================" << endl;
        cout << "1. Ver productos." << endl;
        cout << "2. Ver productos escogidos." << endl;
        cout << "3. Agregar/Modificar producto. " << endl;
        cout << "4. Finalizar escogencia de productos." << endl;
        cout << "====================================================== ================= ==================================================" << endl;
        cout << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarProductos(productos);
                esperar();
                break;
            case 2:
                mostrarProductosEscogidos(productosEscogidos);
                esperar();
                break;

            case 3: {
                string nombreProducto;
                int cantidad;

                // - Mostrar los productos escogidos
                mostrarProductosEscogidos(productosEscogidos);
                cout << " 1. Indique el nombre del producto: ";
                cin >> nombreProducto;

                // - Buscar si el producto que indicó el usuario existe
                Producto* p = buscarProducto(productos,nombreProducto);

                if (p == nullptr) {
                    cout << "No ingresó un nombre de producto válido. Regresando al menú" << endl;
                    esperar();
                    break;
                }

                // - Si existe, mostrarlo para que el usuario esté seguro
                Producto prodBuscado = *p;
                mostrarProducto(prodBuscado);

                // - Si existe el producto en los escogidos se modifica
                if (existeProducto(productosEscogidos, nombreProducto)) {
                    cout << "Este producto ya lo has seleccionado antes." << endl;
                    cout << "Ingresa la cantidad nueva a solicitar del producto: ";
                    cin >> cantidad;
                    actualizarProductoEscogido(productosEscogidos, nombreProducto, cantidad);

                    //sino se agrega al vector
                }else {
                    cout << "Este producto no lo has seleccionado antes." << endl;
                    cout << "Ingresa la cantidad a solicitar del producto: ";
                    cin >> cantidad;
                    insertarProductoEscogido(productosEscogidos, nombreProducto, cantidad);
                }

                esperar();
                break;
            }
            default:
                cout << "Opcion invalida\n";
                esperar();

        }

    }

    return productosEscogidos;
}



void menuCrearOrden() {
    // menu para crear orden
    int opcion = 3;

    vector<ProductoEscogido> productosEscogidos;

    while (opcion == 3) {

        int mesa;

        cout << "\n====================================================== CREAR ORDEN ======================================================\n";
        cout << endl;
        cout << "1. Número de mesa: " << endl;
        cin >> mesa;
        cout << "2. Seleccionar productos: " << endl;
        escogerProductos(productosEscogidos);

        cout << " ====================================================== DATOS DE LA ORDEN ======================================================" << endl;
        cout << "--- Número de mesa: " << mesa << endl;
        cout << endl;
        cout << "--- Productos seleccionados: " << endl;
        mostrarProductosEscogidos(productosEscogidos);
        cout << " ====================================================== ================= ======================================================" << endl;

        cout << endl;
        cout << "Qué desea hacer con la orden ?" << endl;
        cout << "1. Salir y registrar la orden." << endl;
        cout << "2. Salir y no guardar la orden ." << endl;
        cout << "3. Modificar la orden." << endl;
        cin >> opcion;

    }

    // - Si desea guardar la orden
    if (opcion == 1) {

    }

    cout << "\n====================================================== FIN CREAR ORDEN ======================================================" << endl;

}


void menuPrincipal() {
    // menu principal del cliente para registrar/actualizar ordenes
    int opcion = 0;

    while (opcion != 3) {

        cout << "\n====================================================== SISTEMA MESEROS ==================================================" << endl;
        cout << "====================================================== =============== ==================================================" << endl;
        cout << "1. Crear orden\n";
        cout << "2. Modificar orden\n";
        cout << "3. Salir\n";
        cout << "====================================================== =============== ==================================================" << endl;

        cout << endl;
        cout << "Seleccione opcion: ";

        cin >> opcion;

        switch(opcion) {

            case 1:
                limpiar();
                menuCrearOrden();
                break;

            case 2:
                cout << "2. Modificar orden\n";
                //modificarOrden();
                break;

            case 3:
                cout << "\n============================================= SALIENDO SISTEMA MESEROS =============================================" << endl;
                break;

            default:
                cout << "Opcion invalida\n";
        }
    }
}
