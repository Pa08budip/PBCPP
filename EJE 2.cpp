#include <iostream>
#include <fstream>// Libreria para manejo de archivos
#include <sstream> //Libreria para manejo de cadenas
#include <vector> //Libreria para usar vectores
#include <string>

using namespace std;

//Constante para definir el stock mínimo de refacciones, en este caso 10 unidades
const int STOCK_MINIMO = 10;

//Estructura para los datos de las refacciones
struct Refaccion {
    string codigo;
    string nombre;
    string descripcion;
    string marca;
    int existencia;
    float precio;
};
//Estructura para los datos de los proveedores
struct Proveedor {
    string codigo;
    string nombre;
    string contacto;
    string telefono;
    string productos;
};
//Estructura para los datos de las ventas
struct Venta {
    string codigoRefaccion;
    string nombreRefaccion;
    int cantidad;
    float precioUnitario;
    float total;
};

// Función auxiliar para leer un número entero sin que se genere un bucle infinito si se ingresan letras
int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore();
            return valor;
        }
        cout << "Entrada invalida. Por favor ingrese un numero." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// Función auxiliar para leer un número decimal (float) sin que se genere un bucle infinito si se ingresan letras
float leerFlotante(const string& mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore();
            return valor;
        }
        cout << "Entrada invalida. Por favor ingrese un numero valido." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

//Funciones de manejo de archivos

//Vector para cargar las refacciones desde un archivo CSV
vector<Refaccion> cargarRefacciones(const string& nombreArchivo) {
    vector<Refaccion> lista;
    ifstream archivo(nombreArchivo);
    string linea;
    //Ciclo para leer cada línea del archivo y convertirla en un objeto Refaccion
    while (getline(archivo, linea)) {
        //Validación para evitar procesar líneas vacías
        if (linea.empty()) continue;
        stringstream ss(linea);
        string cod, nom, desc, mar, extStr, preStr;

        getline(ss, cod, ',');
        getline(ss, nom, ',');
        getline(ss, desc, ',');
        getline(ss, mar, ',');
        getline(ss, extStr, ',');
        getline(ss, preStr, ',');

        Refaccion r;
        r.codigo = cod;
        r.nombre = nom;
        r.descripcion = desc;
        r.marca = mar;
        r.existencia = stoi(extStr);
        r.precio = stof(preStr);
        lista.push_back(r);
    }

    archivo.close();
    return lista;
}

//Función para guardar la lista de refacciones en un archivo CSV
void guardarRefacciones(const vector<Refaccion>& lista, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    for (size_t i = 0; i < lista.size(); i++) {
        archivo << lista[i].codigo << ","
                << lista[i].nombre << ","
                << lista[i].descripcion << ","
                << lista[i].marca << ","
                << lista[i].existencia << ","
                << lista[i].precio << "\n";
    }
    archivo.close();
}
//Vector para cargar los proveedores desde un archivo CSV
vector<Proveedor> cargarProveedores(const string& nombreArchivo) {
    vector<Proveedor> lista;
    ifstream archivo(nombreArchivo);
    string linea;
    //Ciclo para leer cada línea del archivo y convertirla en un objeto Proveedor
    while (getline(archivo, linea)) {
        //Validación para evitar procesar líneas vacías
        if (linea.empty()) continue;
        stringstream ss(linea);
        Proveedor p;
        getline(ss, p.codigo, ',');
        getline(ss, p.nombre, ',');
        getline(ss, p.contacto, ',');
        getline(ss, p.telefono, ',');
        getline(ss, p.productos, ',');
        lista.push_back(p);
    }

    archivo.close();
    return lista;
}

//Función para guardar la lista de proveedores en un archivo CSV
void guardarProveedores(const vector<Proveedor>& lista, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    for (size_t i = 0; i < lista.size(); i++) {
        archivo << lista[i].codigo << ","
                << lista[i].nombre << ","
                << lista[i].contacto << ","
                << lista[i].telefono << ","
                << lista[i].productos << "\n";
    }
    archivo.close();
}
//Vector para cargar las ventas desde un archivo CSV
vector<Venta> cargarVentas(const string& nombreArchivo) {
    vector<Venta> lista;
    ifstream archivo(nombreArchivo);
    string linea;
    //Ciclo para leer cada línea del archivo y convertirla en un objeto Venta
    while (getline(archivo, linea)) {
        //Validación para evitar procesar líneas vacías
        if (linea.empty()) continue;
        stringstream ss(linea);
        string cantStr, preStr, totStr;
        Venta v;

        getline(ss, v.codigoRefaccion, ',');
        getline(ss, v.nombreRefaccion, ',');
        getline(ss, cantStr, ',');
        getline(ss, preStr, ',');
        getline(ss, totStr, ',');

        v.cantidad = stoi(cantStr);
        v.precioUnitario = stof(preStr);
        v.total = stof(totStr);
        lista.push_back(v);
    }

    archivo.close();
    return lista;
}
//Función para guardar la lista de ventas en un archivo CSV
void guardarVentas(const vector<Venta>& lista, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    for (size_t i = 0; i < lista.size(); i++) {
        archivo << lista[i].codigoRefaccion << ","
                << lista[i].nombreRefaccion << ","
                << lista[i].cantidad << ","
                << lista[i].precioUnitario << ","
                << lista[i].total << "\n";
    }
    archivo.close();
}

//Funciones del Inventario
//Función para buscar una refacción por su código y devolver su posición en el vector
int buscarRefaccionPorCodigo(const vector<Refaccion>& refacciones, const string& codigo) {
    for (size_t i = 0; i < refacciones.size(); i++) {
        if (refacciones[i].codigo == codigo) {
            return (int)i;
        }
    }
    return -1;
}
//Función para mostrar los detalles de una refacción
void mostrarRefaccion(const Refaccion& r) {
    cout << "Codigo: " << r.codigo << endl;
    cout << "Nombre: " << r.nombre << endl;
    cout << "Descripcion: " << r.descripcion << endl;
    cout << "Marca: " << r.marca << endl;
    cout << "Precio: $" << r.precio << endl;
    cout << "Existencia: " << r.existencia << endl;
    if (r.existencia < STOCK_MINIMO) {
        cout << "[ALERTA] Existencia baja (menor a " << STOCK_MINIMO << " unidades)." << endl;
    }
}
//Funciones del menú de inventario
//Función para registrar una nueva refacción
void registrarRefaccion(vector<Refaccion>& refacciones) {
    Refaccion r;
    cout << "Registra una nueva refaccion" << endl;
    cout << "Codigo: ";
    getline(cin, r.codigo);
    // Validación para evitar duplicados
    if (buscarRefaccionPorCodigo(refacciones, r.codigo) != -1) {
        cout << "Error: Ya existe una refaccion con ese codigo." << endl;
        return;
    }

    cout << "Nombre: ";
    getline(cin, r.nombre);
    cout << "Descripcion: ";
    getline(cin, r.descripcion);
    cout << "Marca: ";
    getline(cin, r.marca);
    //Ciclo para asegurar que el precio sea valos válido(no negativo)
    do {
        r.precio = leerFlotante("Precio unitario: ");
        if (r.precio < 0) {
            cout << "El precio no puede ser negativo." << endl;
        }
    } while (r.precio < 0);
    //Ciclo para asegurar que la existencia sea un valor válido (no negativo)
    do {
        r.existencia = leerEntero("Existencia inicial: ");
        if (r.existencia < 0) {
            cout << "La existencia no puede ser negativa." << endl;
        }
    } while (r.existencia < 0);

    refacciones.push_back(r);
    cout << "Refaccion registrada con exito." << endl;
}
//Función para consultar una refacción por código o nombre
void consultarRefaccion(const vector<Refaccion>& refacciones) {
    cout << "Consultar refaccion" << endl;
    cout << "1. Buscar por codigo" << endl;
    cout << "2. Buscar por nombre" << endl;
    int tipoBusqueda = leerEntero("Seleccione una opcion: ");

    bool encontrada = false;
    if (tipoBusqueda == 1) {
        string codigo;
        cout << "Ingrese el codigo: ";
        getline(cin, codigo);
        int pos = buscarRefaccionPorCodigo(refacciones, codigo);
        if (pos != -1) {
            cout << "\nRefaccion encontrada:\n";
            mostrarRefaccion(refacciones[pos]);
            encontrada = true;
        }
    } else if (tipoBusqueda == 2) {
        string nombre;
        cout << "Ingrese el nombre: ";
        getline(cin, nombre);
        for (size_t i = 0; i < refacciones.size(); i++) {
            if (refacciones[i].nombre == nombre) {
                cout << "\nRefaccion encontrada:\n";
                mostrarRefaccion(refacciones[i]);
                encontrada = true;
            }
        }
    } else {
        cout << "Opcion de busqueda invalida." << endl;
        return;
    }

    if (!encontrada) {
        cout << "No se encontro ninguna refaccion con ese criterio." << endl;
    }
}
//Función para registrar la entrada de mercancía y actualizar la existencia
void registrarEntradaMercancia(vector<Refaccion>& refacciones) {
    string codigo;
    int cantidadEntrada;

    cout << "Registrar entrada de mercancía" << endl;
    cout << "Codigo de la refaccion: ";
    getline(cin, codigo);

    int pos = buscarRefaccionPorCodigo(refacciones, codigo);
    if (pos == -1) {
        cout << "Refaccion no encontrada." << endl;
        return;
    }

    cout << "Refaccion: " << refacciones[pos].nombre
         << " | Existencia actual: " << refacciones[pos].existencia << endl;

    do {
        cantidadEntrada = leerEntero("Cantidad a ingresar: ");
        if (cantidadEntrada <= 0) {
            cout << "Ingrese una cantidad mayor a cero." << endl;
        }
    } while (cantidadEntrada <= 0);

    refacciones[pos].existencia += cantidadEntrada;
    cout << "Entrada registrada. Nueva existencia: " << refacciones[pos].existencia << endl;
}
//Función para mostrar el menú de gestión de inventario
void menuInventario(vector<Refaccion>& refacciones, const string& archivoRefacciones) {
    int opcion;
    do {
        cout << "Sistema de Gestión de Inventario" << endl;
        cout << "1. Registrar refaccion" << endl;
        cout << "2. Consultar refaccion" << endl;
        cout << "3. Registrar entrada de mercancia" << endl;
        cout << "4. Regresar al menu principal" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                registrarRefaccion(refacciones);
                guardarRefacciones(refacciones, archivoRefacciones);
                break;
            case 2:
                consultarRefaccion(refacciones);
                break;
            case 3:
                registrarEntradaMercancia(refacciones);
                guardarRefacciones(refacciones, archivoRefacciones);
                break;
            case 4:
                cout << "Regresando al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);
}

//Función para registrar ventas y actualizar inventario
void registrarVenta(vector<Refaccion>& refacciones, vector<Venta>& ventas,
                   const string& archivoRefacciones, const string& archivoVentas) {
    float totalVenta = 0.0f;
    char continuar = 's';

    cout << "Registrar venta" << endl;
     //Ciclo para permitir registrar múltiples productos en una sola venta
    while (continuar == 's' || continuar == 'S') {
        string codigo;
        cout << "Ingrese el codigo de la refaccion: ";
        getline(cin, codigo);

        int pos = buscarRefaccionPorCodigo(refacciones, codigo);
        if (pos == -1) {
            cout << "Producto no encontrado. Verifique el codigo." << endl;
        } else {
            cout << "Producto: " << refacciones[pos].nombre
                 << " | Precio: $" << refacciones[pos].precio
                 << " | Existencia: " << refacciones[pos].existencia << endl;

            int cantidad = leerEntero("Cantidad a vender: ");

            if (cantidad <= 0 || cantidad > refacciones[pos].existencia) {
                cout << "Cantidad invalida o stock insuficiente. Existencia actual: "
                     << refacciones[pos].existencia << endl;
            } else {
                float subtotal = cantidad * refacciones[pos].precio;
                totalVenta += subtotal;
                refacciones[pos].existencia -= cantidad;

                Venta v;
                v.codigoRefaccion = refacciones[pos].codigo;
                v.nombreRefaccion = refacciones[pos].nombre;
                v.cantidad = cantidad;
                v.precioUnitario = refacciones[pos].precio;
                v.total = subtotal;
                ventas.push_back(v);

                cout << "Subtotal agregado: $" << subtotal << endl;
            }
        }

        cout << "Desea agregar otro producto a la venta? (s/n): ";
        cin >> continuar;
        cin.ignore();
    }

    cout << "Total de la venta: $" << totalVenta << endl;
    guardarRefacciones(refacciones, archivoRefacciones);
    guardarVentas(ventas, archivoVentas);
}

// Funciones del menú de gestión de proveedores

//Función para buscar un proveedor por su código y devolver su posición en el vector
int buscarProveedorPorCodigo(const vector<Proveedor>& proveedores, const string& codigo) {
    for (size_t i = 0; i < proveedores.size(); i++) {
        if (proveedores[i].codigo == codigo) {
            return (int)i;
        }
    }
    return -1;
}
//Función para registrar un nuevo proveedor
void registrarProveedor(vector<Proveedor>& proveedores) {
    Proveedor p;
    cout << "Registrar proveedor" << endl;
    cout << "Codigo del proveedor: ";
    getline(cin, p.codigo);

    if (buscarProveedorPorCodigo(proveedores, p.codigo) != -1) {
        cout << "Error: El codigo de proveedor ya existe." << endl;
        return;
    }

    cout << "Nombre o razon social: ";
    getline(cin, p.nombre);
    cout << "Persona de contacto: ";
    getline(cin, p.contacto);
    cout << "Telefono: ";
    getline(cin, p.telefono);
    cout << "Productos que suministra: ";
    getline(cin, p.productos);

    proveedores.push_back(p);
    cout << "Proveedor registrado con exito." << endl;
}
//Función para consultar un proveedor por código
void consultarProveedor(const vector<Proveedor>& proveedores) {
    string codigo;
    cout << "Consultar proveedor" << endl;
    cout << "Codigo del proveedor a consultar: ";
    getline(cin, codigo);

    int pos = buscarProveedorPorCodigo(proveedores, codigo);
    if (pos == -1) {
        cout << "Proveedor no encontrado." << endl;
    } else {
        cout << "\nNombre: " << proveedores[pos].nombre << endl;
        cout << "Contacto: " << proveedores[pos].contacto << endl;
        cout << "Telefono: " << proveedores[pos].telefono << endl;
        cout << "Productos: " << proveedores[pos].productos << endl;
    }
}
//Función para modificar los datos de un proveedor existente
void modificarProveedor(vector<Proveedor>& proveedores) {
    string codigo;
    cout << "Modificar proveedor" << endl;
    cout << "Codigo del proveedor a modificar: ";
    getline(cin, codigo);

    int pos = buscarProveedorPorCodigo(proveedores, codigo);
    if (pos == -1) {
        cout << "Proveedor no encontrado." << endl;
        return;
    }

    cout << "Nuevo nombre o razon social: ";
    getline(cin, proveedores[pos].nombre);
    cout << "Nueva persona de contacto: ";
    getline(cin, proveedores[pos].contacto);
    cout << "Nuevo telefono: ";
    getline(cin, proveedores[pos].telefono);
    cout << "Nuevos productos que suministra: ";
    getline(cin, proveedores[pos].productos);

    cout << "Datos del proveedor actualizados con exito." << endl;
}
//Función para mostrar el menú de gestión de proveedores
void menuProveedores(vector<Proveedor>& proveedores, const string& archivoProveedores) {
    int opcion;
    do {
        cout << "Gestionar proveedores" << endl;
        cout << "1. Registrar proveedor" << endl;
        cout << "2. Consultar proveedor por codigo" << endl;
        cout << "3. Modificar proveedor" << endl;
        cout << "4. Regresar al menu principal" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                registrarProveedor(proveedores);
                guardarProveedores(proveedores, archivoProveedores);
                break;
            case 2:
                consultarProveedor(proveedores);
                break;
            case 3:
                modificarProveedor(proveedores);
                guardarProveedores(proveedores, archivoProveedores);
                break;
            case 4:
                cout << "Regresando al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);
}

//Funciones de reportes
//Función para generar un reporte completo del inventario, mostrando cada refacción y su valor total
void reporteInventarioCompleto(const vector<Refaccion>& refacciones) {
    float valorTotalInventario = 0.0f;
    cout << "Reporte de inventario completo" << endl;

    if (refacciones.empty()) {
        cout << "No hay refacciones registradas." << endl;
        return;
    }

    for (size_t i = 0; i < refacciones.size(); i++) {
        float subtotalValor = refacciones[i].precio * refacciones[i].existencia;
        valorTotalInventario += subtotalValor;
        cout << i + 1 << ". [" << refacciones[i].codigo << "] "
             << refacciones[i].nombre
             << " | Existencia: " << refacciones[i].existencia
             << " | Precio: $" << refacciones[i].precio
             << " | Valor: $" << subtotalValor << endl;
    }
    cout << "Valor total del inventario: $" << valorTotalInventario << endl;
}
//Función para generar un reporte de refacciones con existencias bajas, mostrando aquellas que están por debajo del stock mínimo
void reporteExistenciasBajas(const vector<Refaccion>& refacciones) {
    bool hayBajas = false;
    cout << "Reporte de existencias bajas" << endl;

    for (size_t i = 0; i < refacciones.size(); i++) {
        if (refacciones[i].existencia < STOCK_MINIMO) {
            cout << "Refaccion: " << refacciones[i].nombre
                 << " (" << refacciones[i].codigo << ")"
                 << " | Existencia actual: " << refacciones[i].existencia << endl;
            hayBajas = true;
        }
    }

    if (!hayBajas) {
        cout << "No hay refacciones con existencia baja." << endl;
    }
}
//Función para generar un reporte de ventas realizadas, mostrando cada venta y el total acumulado
void reporteVentas(const vector<Venta>& ventas) {
    float totalAcumulado = 0.0f;
    cout << "Reporte de ventas realizadas" << endl;

    if (ventas.empty()) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    for (size_t i = 0; i < ventas.size(); i++) {
        totalAcumulado += ventas[i].total;
        cout << i + 1 << ". [" << ventas[i].codigoRefaccion << "] "
             << ventas[i].nombreRefaccion
             << " | Cant: " << ventas[i].cantidad
             << " | Unitario: $" << ventas[i].precioUnitario
             << " | Total: $" << ventas[i].total << endl;
    }
    cout << "Total acumulado de ventas: $" << totalAcumulado << endl;
}
//Función para mostrar el submenú de reportes y permitir al usuario elegir qué reporte generar
void menuReportes(const vector<Refaccion>& refacciones, const vector<Venta>& ventas) {
    int opcion;
    do {
        cout << "Generar reportes" << endl;
        cout << "1. Reporte de inventario completo" << endl;
        cout << "2. Reporte de existencias bajas" << endl;
        cout << "3. Reporte de ventas realizadas" << endl;
        cout << "4. Regresar al menu principal" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                reporteInventarioCompleto(refacciones);
                break;
            case 2:
                reporteExistenciasBajas(refacciones);
                break;
            case 3:
                reporteVentas(ventas);
                break;
            case 4:
                cout << "Regresando al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);
}

//Main
int main() {
    const string ARCHIVO_REFACCIONES = "refacciones.csv";
    const string ARCHIVO_PROVEEDORES = "proveedores.csv";
    const string ARCHIVO_VENTAS = "ventas.csv";

    vector<Refaccion> refacciones = cargarRefacciones(ARCHIVO_REFACCIONES);
    vector<Proveedor> proveedores = cargarProveedores(ARCHIVO_PROVEEDORES);
    vector<Venta> ventas = cargarVentas(ARCHIVO_VENTAS);
//Menú principal del sistema
    int opcion;
    do {
        cout << " SISTEMA DE GESTION - REFACCIONARIA INDUSTRIAL" << endl;
        cout << "1. Gestionar Inventario" << endl;
        cout << "2. Registrar Venta" << endl;
        cout << "3. Gestionar Proveedores" << endl;
        cout << "4. Generar Reportes" << endl;
        cout << "0. Salir del Sistema" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                menuInventario(refacciones, ARCHIVO_REFACCIONES);
                break;
            case 2:
                registrarVenta(refacciones, ventas, ARCHIVO_REFACCIONES, ARCHIVO_VENTAS);
                break;
            case 3:
                menuProveedores(proveedores, ARCHIVO_PROVEEDORES);
                break;
            case 4:
                menuReportes(refacciones, ventas);
                break;
            case 0:
                guardarRefacciones(refacciones, ARCHIVO_REFACCIONES);
                guardarProveedores(proveedores, ARCHIVO_PROVEEDORES);
                guardarVentas(ventas, ARCHIVO_VENTAS);
                cout << "Cerrando el sistema... ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);

    return 0;
}