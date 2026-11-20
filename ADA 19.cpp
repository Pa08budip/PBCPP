#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //Arreglo tridimensional
    float ventas[3][4][3];
    //Llenar el arreglo con datos de ventas
    for (int a = 0; a < 3; a++) {
        cout << "Ano " << (a + 1) << endl;
        for (int p = 0; p < 3; p++) {
            cout << "Producto " << (p + 1) << endl;
            for (int t = 0; t < 4; t++) {
                cout << "Trimestre " << (t + 1) << ": ";
                cin >> ventas[p][t][a];
            }
        }
    }
    //Para mostrar 2 decimales en los promedios
    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Ventas Registradas: " << endl;
    for (int a = 0; a < 3; a++) {
        cout << "Ano " << (a + 1) << ":" << endl;
        for (int p = 0; p < 3; p++) {
            cout << "  Producto " << (p + 1) << ": ";
            for (int t = 0; t < 4; t++) {
                cout << "Trimestre " << (t + 1) << ": " << ventas[p][t][a] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Promedio Anual Por Producto: " << endl;
    for (int a = 0; a < 3; a++) {
        cout << "Ano " << (a + 1) << endl;
        for (int p = 0; p < 3; p++) {
            float suma_Producto = 0.0f;
            for (int t = 0; t < 4; t++) {
                suma_Producto += ventas[p][t][a];
            }
            float promedio_Producto = suma_Producto / 4.0f;
            cout << "Producto " << (p + 1) << ": " << promedio_Producto << endl;
        }
        cout << endl;
    }

    cout << "Promedio de Ventas Por Ano: " << endl;
    for (int a = 0; a < 3; a++) {
        float suma_año = 0.0f;
        for (int p = 0; p < 3; p++) {
            for (int t = 0; t < 4; t++) {
                suma_año += ventas[p][t][a];
            }
        }
        float promedio_Año = suma_año / 12.0f;
        cout << "Ano " << (a + 1) << ": " << promedio_Año << endl;
    }
    cout << endl;

    cout << "Promedio General: " << endl;
    float suma_general = 0.0f;
    for (int a = 0; a < 3; a++) {
        for (int p = 0; p < 3; p++) {
            for (int t = 0; t < 4; t++) {
                suma_general += ventas[p][t][a];
            }
        }
    }
    float promedioGeneral = suma_general / 36.0f;
    cout << "Promedio de los 3 anos: " << promedioGeneral << endl;

    return 0;
}