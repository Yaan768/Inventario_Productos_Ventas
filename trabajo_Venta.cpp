#include <iostream>
using namespace std;

int main() {
    char opcion;

    do {
        cout << "======================================" << endl;
        cout << "     INVENTARIO DE PRODUCTOS Y VENTAS " << endl;
        cout << "======================================" << endl;
        cout << "A: Registrar un nuevo producto" << endl;
        cout << "B: Listar los productos registrados" << endl;
        cout << "C: Buscar un producto por nombre" << endl;
        cout << "D: Actualizar los datos de un producto" << endl;
        cout << "E: Eliminar un producto" << endl;
        cout << "F: Registrar una venta" << endl;
        cout << "G: Listar las ventas realizadas" << endl;
        cout << "H: Calcular el total de ventas realizadas" << endl;
        cout << "S: Salir del programa" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        opcion = toupper(opcion); // Asegurarse de que sea mayúscula

        switch(opcion) {
            case 'A':
                cout << "Registrar un nuevo producto\n";
                // en proceso 
                break;
            case 'B':
                cout << "Listar los productos registrados\n";
                // en proceso 
                break;
            case 'C':
                cout << "Buscar un producto por nombre\n";
                // en proceso 
                break;
            case 'D':
                cout << "Actualizar los datos de un producto\n";
                // en proceso 
                break;
            case 'E':
                cout << "Eliminar un producto\n";
                // en proceso 
                break;
            case 'F':
                cout << "Registrar una venta\n";
                // en proceso 
                break;
            case 'G':
                cout << "Listar las ventas realizadas\n";
                // en proceso 
                break;
            case 'H':
                cout << "Calcular el total de ventas realizadas\n";
                // en proceso 
                break;
            case 'S':
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }

        cout << endl;

    } while(opcion != 'S');

    return 0;
}

