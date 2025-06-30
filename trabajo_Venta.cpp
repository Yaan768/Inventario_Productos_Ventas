#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS = 100;

struct Producto {
    string nombre;
    float precio;
};

Producto productos[MAX_PRODUCTOS];
int totalProductos = 0;

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
        cin.ignore(); 

        opcion = toupper(opcion); 

        switch(opcion) {
            case 'A': {
                if (totalProductos >= MAX_PRODUCTOS) {
                    cout << "No se puede registrar mas productos. Limite alcanzado.\n";
                } else {
                    Producto nuevo;
                    cout << "Ingrese nombre del producto: ";
                    getline(cin, nuevo.nombre);
                    cout << "Ingrese precio del producto: ";
                    cin >> nuevo.precio;
                    cin.ignore();

                    productos[totalProductos] = nuevo;
                    totalProductos++;

                    cout << "Producto registrado exitosamente.\n";
                }
                break;
            }
            case 'B': {
                if (totalProductos == 0) {
                    cout << "No hay productos registrados.\n";
                } else {
                    cout << "\n--- Lista de Productos ---\n";
                    for (int i = 0; i < totalProductos; i++) {
                        cout << i + 1 << ". Nombre: " << productos[i].nombre
                             << " | Precio: S/ " << productos[i].precio << endl;
                    }
                }
                break;
            }
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
                cout << "Opcion no valida. Intente de nuevo.\n";
        }

        cout << endl;

    } while(opcion != 'S');

    return 0;
}

