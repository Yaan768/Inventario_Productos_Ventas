#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS = 100;
const int MAX_VENTAS = 100;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

Producto productos[MAX_PRODUCTOS];
int totalProductos = 0;

Venta ventas[MAX_VENTAS];
int totalVentas = 0;

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
                    cout << "No se puede registrar más productos. Límite alcanzado.\n";
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
            case 'C': {
                if (totalProductos == 0) {
                    cout << "No hay productos para buscar.\n";
                } else {
                    string nombreBuscado;
                    cout << "Ingrese el nombre del producto a buscar: ";
                    getline(cin, nombreBuscado);

                    bool encontrado = false;
                    for (int i = 0; i < totalProductos; i++) {
                        if (productos[i].nombre == nombreBuscado) {
                            cout << "Producto encontrado: " << productos[i].nombre
                                 << " | Precio: S/ " << productos[i].precio << endl;
                            encontrado = true;
                            break;
                        }
                    }

                    if (!encontrado) {
                        cout << "Producto no encontrado.\n";
                    }
                }
                break;
            }
            case 'D': {
                if (totalProductos == 0) {
                    cout << "No hay productos para actualizar.\n";
                } else {
                    string nombreBuscado;
                    cout << "Ingrese el nombre del producto a actualizar: ";
                    getline(cin, nombreBuscado);

                    bool actualizado = false;
                    for (int i = 0; i < totalProductos; i++) {
                        if (productos[i].nombre == nombreBuscado) {
                            cout << "Ingrese el nuevo nombre: ";
                            getline(cin, productos[i].nombre);
                            cout << "Ingrese el nuevo precio: ";
                            cin >> productos[i].precio;
                            cin.ignore();
                            cout << "Producto actualizado correctamente.\n";
                            actualizado = true;
                            break;
                        }
                    }

                    if (!actualizado) {
                        cout << "Producto no encontrado.\n";
                    }
                }
                break;
            }
            case 'E': {
                if (totalProductos == 0) {
                    cout << "No hay productos para eliminar.\n";
                } else {
                    string nombreEliminar;
                    cout << "Ingrese el nombre del producto a eliminar: ";
                    getline(cin, nombreEliminar);

                    bool eliminado = false;
                    for (int i = 0; i < totalProductos; i++) {
                        if (productos[i].nombre == nombreEliminar) {
                            for (int j = i; j < totalProductos - 1; j++) {
                                productos[j] = productos[j + 1];
                            }
                            totalProductos--;
                            cout << "Producto eliminado exitosamente.\n";
                            eliminado = true;
                            break;
                        }
                    }

                    if (!eliminado) {
                        cout << "Producto no encontrado.\n";
                    }
                }
                break;
            }
            case 'F': {
                if (totalProductos == 0) {
                    cout << "No hay productos disponibles para vender.\n";
                } else if (totalVentas >= MAX_VENTAS) {
                    cout << "No se puede registrar más ventas. Límite alcanzado.\n";
                } else {
                    string nombreProducto;
                    cout << "Ingrese el nombre del producto a vender: ";
                    getline(cin, nombreProducto);

                    int indice = -1;
                    for (int i = 0; i < totalProductos; i++) {
                        if (productos[i].nombre == nombreProducto) {
                            indice = i;
                            break;
                        }
                    }

                    if (indice == -1) {
                        cout << "Producto no encontrado.\n";
                    } else {
                        Venta nuevaVenta;
                        nuevaVenta.idVenta = totalVentas + 1;
                        nuevaVenta.producto = nombreProducto;

                        cout << "Ingrese la cantidad vendida: ";
                        cin >> nuevaVenta.cantidad;
                        cin.ignore();

                        nuevaVenta.precioTotal = productos[indice].precio * nuevaVenta.cantidad;

                        ventas[totalVentas] = nuevaVenta;
                        totalVentas++;

                        cout << "Venta registrada exitosamente. Total: S/ " << nuevaVenta.precioTotal << endl;
                    }
                }
                break;
            }
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




