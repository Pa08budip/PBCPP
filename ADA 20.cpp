#include <iostream>
#include <cmath>   
#include <iomanip> 
using namespace std;

int main() {
    char continuar;
    // Ciclo para repetir el programa ahsta que el usuario decida salir
    do {
        float ventas[12];
        float sumaVentas = 0.0f;
        float promedio = 0.0f;
        float sumaDiferenciasCuadradas = 0.0f;
        float desviacionEstandar = 0.0f;
        int opcionCategoria = 0;
        float inventarioMaximo = 0.0f;
        cout << "Control de Inventario" << endl;
        //Llenado del arreglo de ventas mensuales
        cout << "\nIngrese las ventas mensuales del producto" << endl;
        for (int i = 0; i < 12; i++) {
            cout << "Mes " << (i + 1) << ": ";
            cin >> ventas[i];
            sumaVentas += ventas[i];
        }
        // Calcular promedio
        promedio = sumaVentas / 12.0f;
        // Calcular desviación estándar
        for (int i = 0; i < 12; i++) {
            float diferencia = ventas[i] - promedio;
            sumaDiferenciasCuadradas += diferencia * diferencia;
        }
        desviacionEstandar = sqrt(sumaDiferenciasCuadradas / 12.0f);

        // Impimir a tres decimales
        cout << fixed << setprecision(3);
        cout << "\n" << endl;
        cout << "Promedio de ventas (m): " << promedio << endl;
        cout << "Desviacion Estandar (ds): " << desviacionEstandar << endl;

        // Productos por categoría
        cout << "\nSeleccione la categoria del producto:" << endl;
        cout << "1. Medio        (Promedio + 1 Desviacion Estandar)" << endl;
        cout << "2. Importante   (Promedio + 2 Desviaciones Estandar)" << endl;
        cout << "3. Indispensable (Promedio + 3 Desviaciones Estandar)" << endl;
        cout << "Opcion (1-3): ";
        cin >> opcionCategoria;

        // Determinar la cantidad de inventario requerida según la fórmula correspondiente
        switch (opcionCategoria) {
            case 1:
                inventarioMaximo = promedio + (1 * desviacionEstandar);
                cout << "\nCategoria: Medio" << endl;
                cout << "Formula: (m + 1*(ds)) = " << promedio << " + 1*" << desviacionEstandar << endl;
                break;

            case 2:
                inventarioMaximo = promedio + (2 * desviacionEstandar);
                cout << "\nCategoria: Importante" << endl;
                cout << "Formula: (m + 2*(ds)) = " << promedio << " + 2*" << desviacionEstandar << endl;
                break;

            case 3:
                inventarioMaximo = promedio + (3 * desviacionEstandar);
                cout << "\nCategoria: Indispensable" << endl;
                cout << "Formula: (m + 3*(ds)) = " << promedio << " + 3*" << desviacionEstandar << endl;
                break;

            default:
                cout << "\nOpcion no valida. Se calculara por defecto como categoria Medio." << endl;
                inventarioMaximo = promedio + (1 * desviacionEstandar);
                break;
        }

        cout << "Cantidad a mantener en inventario: " << inventarioMaximo << endl;
        cout << "\n¿Desea analizar otro producto? (s/n): ";
        cin >> continuar;
        cout << endl;

    } while (continuar == 's');

    cout << "Programa finalizado. ¡Hasta luego!" << endl;

    return 0;
}