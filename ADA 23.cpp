#include <iostream>

using namespace std;
int main() {
    int tamano = 10;
    int identificadores[tamano];
    cout << "Ingrese los IDs numericos de los " << tamano << " paquetes:" << endl;
    //Llenado del arreglo
    for (int i = 0; i < tamano; i++) {
        cout << "Paquete [" << i + 1 << "]: ";
        cin >> identificadores[i];
    }
    //Mostrar el arreglo original
    cout << "\nArreglo original: [ ";
    for (int i = 0; i < tamano; i++) {
        cout << identificadores[i] << " ";
    }
    cout << "]" << endl;
    // Bucle externo para recorrer la sublista no ordenada de izquierda a derecha
    for (int i = 0; i < tamano - 1; i++) {
        // Primero el elemento i es el mínimo
        int siguiente_Min = i;
        // Bucle interno para buscar la posicion del elemento minimo en el resto del arreglo
        for (int j = i + 1; j < tamano; j++) {
            if (identificadores[j] < identificadores[siguiente_Min]) {
                siguiente_Min = j; // Actualizacion del indice del value minimo encontrado
            }
        }
        //Swap si el minimo encontrado no es el mismo que el elemento i
        if (siguiente_Min != i) {
            int temporal = identificadores[i];
            identificadores[i] = identificadores[siguiente_Min];
            identificadores[siguiente_Min] = temporal;
        }
        // Impresion de seguimiento por pasada
        cout << "Pasada " << i + 1 << " (Indice minimo encontrado: " << siguiente_Min << "): [ ";
        for (int k = 0; k < tamano; k++) {
            cout << identificadores[k] << " ";
        }
        cout << "]" << endl;
    }
    cout << "\nArreglo final ordenado ascendente: [ ";
    for (int i = 0; i < tamano; i++) {
        cout << identificadores[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}