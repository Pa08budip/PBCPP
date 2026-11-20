#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    srand(time(0));
    // Arreglos para almacenar los alimentos y sus precios
    string alimentos[5] = {"Hamburguesa", "Hog dog", "Torta", "Taco", "Burrito"};
    double precios[5] = {180.00, 60.00, 65.00, 35.00, 220.00};
    // Arreglos para almacenar las ventas y los ingresos
    int ventas[5] = {0};
    double ingresos[5] = {0.0};

    for (int i = 0; i < 100; i++) {
        int indice = rand() % 5;
        ventas[indice]++;
    }

    // Para calcular el ingreso de los alimentos vendidos multiplico el precio por la cantidad de ventas
    for (int i = 0; i < 5; i++) {
        ingresos[i] = ventas[i] * precios[i];
    }

    // Sirve para saber el alimento más vendido y el que generó mayor ingreso
    int idxMasVendido = 0;
    int idxMayorIngreso = 0;

    for (int i = 1; i < 5; i++) {
        if (ventas[i] > ventas[idxMasVendido]) {
            idxMasVendido = i;
        }
        if (ingresos[i] > ingresos[idxMayorIngreso]) {
            idxMayorIngreso = i;
        }
    }

    //Es para la tabla
    cout << left << setw(15) << "Alimento"
         << setw(10) << "Ventas"
         << "Ingresos" << endl;

    for (int i = 0; i < 5; i++) {
        cout << left << setw(15) << alimentos[i]
             << setw(10) << ventas[i]
             << fixed << setprecision(0) << ingresos[i] << endl;
    }

    cout << endl;
    cout << "El mas vendido es: " << alimentos[idxMasVendido] << endl;
    cout << "El de mayor ingreso es: " << alimentos[idxMayorIngreso] << endl;

    return 0;
}