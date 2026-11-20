#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
    ofstream archivo;
    archivo.open("lista_tareas.txt");
    if (archivo.is_open()) {
        string tarea;
        cout << "Ingrese 3 tareas:" << endl;
        for (int i = 1; i <= 3; i++) {
            getline(cin, tarea);
            archivo << "Tarea " << i << ": " << tarea << endl;
        }
        archivo.close();
        cout << "Tareas guardadas en lista_tareas.txt" << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    ifstream archivoEntrada;
    archivoEntrada.open("lista_tareas.txt");
    if (archivoEntrada.is_open()) {
        string linea;
        cout << "\nMis tareas para hoy:" << endl;
        while(getline(archivoEntrada, linea)) {
            cout << linea << endl;
        }
        archivoEntrada.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return 0;
}