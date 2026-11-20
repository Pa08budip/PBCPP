
#include <iostream>
using namespace std;

int tamano = 5;

// Prototipo de la función usando un arreglo bidimensional
void Combinaciones(int arr[][2], int tamano);
// Prototipo de la función para calcular el factorial de un número
int Factorial(int n);

int main() {
    // Declaración del arreglo bidimensional (5 pares, 2 números por par)
    int arr[5][2];

    // Imprimir las combinaciones de los pares de números ingresados usando la función Combinaciones
    Combinaciones(arr, tamano);

    return 0;
}

// Función para pedir datos y calcular las combinaciones
void Combinaciones(int arr[][2], int tamano) {
    // Ciclo para llenar la matriz con los 5 pares de números
    cout << "Ingrese 5 pares de numeros: " << endl;
    for (int i = 0; i < tamano; i++) {
        cout << "Par " << i + 1 << endl;
        cout << "Numero 1: ";
        cin >> arr[i][0];
        cout << "Numero 2: ";
        cin >> arr[i][1];

        // Validación de que el segundo número no sea mayor que el primero
        while (arr[i][0] < arr[i][1]) {
            cout << "El primer numero es menor que el segundo, ingrese otro numero 1: " << endl;
            cin >> arr[i][0];
        }
    }

    cout << "\nLas combinaciones de los pares de numeros ingresados son: " << endl;
    
    // Ciclo para calcular e imprimir las combinaciones de cada fila
    for (int i = 0; i < tamano; i++) {
        int n = arr[i][0];
        int r = arr[i][1];
        int combinaciones = Factorial(n) / (Factorial(r) * Factorial(n - r));
        
        cout << "Combinacion del par " << i + 1 << " (" << n << ", " << r << "): " << combinaciones << endl;
    }
}

// Función para calcular el factorial de un número
int Factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}