#include <iostream>
using namespace std;
int main()
{
    int tamano;
    cout << "Tamaño de la matriz: " << endl;
    cin >> tamano;
    const int filas = tamano;
    const int columnas = tamano;
    int matriz_A[filas][columnas];
    int matriz_B[filas][columnas];
    int matriz_C[filas][columnas];
    cout << "Llena la Matriz A" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Matriz_A[" << i << "][" << j << "]: ";
            cin >> matriz_A[i][j];
        }
    }
    cout << "Llena la Matriz B" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Matriz_B[" << i << "][" << j << "]: ";
            cin >> matriz_B[i][j];
        }
    }
    cout << "Matriz C" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_C[i][j] = matriz_A[i][j] + matriz_B[i][j];
            cout << matriz_C[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}