#include <iostream>
#include <fstream> // Librería para usar los archivos
#include <iomanip> // Librería para usar setprecision
#include <vector>  // Librería para usar vectores
using namespace std;

// Función para ingresar las calificaciones de los estudiantes
void ingresarCalificaciones(vector<vector<double>>& calificaciones, int n, int asignaturas) {
    cout << "Ingresa las calificaciones de los estudiantes por asignatura en una escala del 0 al 100:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < asignaturas; j++) { 
            do {
                cout << "Ingrese la calificación del estudiante " << (i + 1) << " para la asignatura " << (j + 1) << ": ";
                cin >> calificaciones[i][j];
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 100) {
                    cout << "Calificación inválida. Debe estar entre 0 y 100" << endl;
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 100);
        } // Cierra el ciclo de las asignaturas
    } // Cierra el ciclo de los estudiantes
}

// Función para calcular el promedio general del grupo
double calcularPromedioGeneral(const vector<vector<double>>& calificaciones, int n, int asignaturas) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < asignaturas; j++) {
            suma += calificaciones[i][j];
        }
    }
    return (n * asignaturas > 0) ? (suma / (n * asignaturas)) : 0;  //Evita que se divida entre cero
}

// Función para calcular el promedio individual de un estudiante
double calcularPromedioEstudiante(const vector<double>& estudiante, int asignaturas) {
    double suma = 0;
    for (int j = 0; j < asignaturas; j++) {
        suma += estudiante[j];
    }
    return (asignaturas > 0) ? (suma / asignaturas) : 0; //Evita que se divida entre cero
}

// Función para encontrar la calificación más alta y la más baja por referencia
void encontrarMaxMin(const vector<vector<double>>& calificaciones, int n, int asignaturas, double &maxima, double &minima) {
    maxima = calificaciones[0][0];
    minima = calificaciones[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < asignaturas; j++) {
            if (calificaciones[i][j] > maxima) {
                maxima = calificaciones[i][j];
            }
            if (calificaciones[i][j] < minima) {
                minima = calificaciones[i][j];
            }
        }
    }
}

// Función para guardar los resultados en un archivo de texto
void guardarResultados(const vector<vector<double>>& calificaciones, int n, int asignaturas, double promedioGeneral, double maxima, double minima) {
    ofstream archivo("Calificaciones.txt", ios::out);
    
    if (archivo.is_open()) {
        archivo << "Calificaciones de los estudiantes" << endl;    
        archivo << "Listado de calificaciones por estudiante:" << endl;
        for (int i = 0; i < n; i++) {
            archivo << "Estudiante " << (i + 1) << ": ";
            for (int j = 0; j < asignaturas; j++) {
                archivo << fixed << setprecision(2) << calificaciones[i][j] << " ";
            }
            archivo << endl;
        }
        archivo << "Promedio general del grupo: " << fixed << setprecision(2) << promedioGeneral << endl;
        archivo << "Calificación máxima: " << fixed << setprecision(2) << maxima << endl;
        archivo << "Calificación mínima: " << fixed << setprecision(2) << minima << endl;
        archivo.close();
        cout << "Se registraron los resultados en el archivo 'Calificaciones.txt'." << endl;   
    } else {
        cout << "No se pudo abrir el archivo para guardar los resultados." << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el número total de estudiantes: ";
    cin >> n;
    if (n <= 0) {
        cout << "Número de estudiantes inválido." << endl;
        return 1;
    }
    
    int asignaturas;
    cout << "Ingrese el número de asignaturas: ";
    cin >> asignaturas;
    if (asignaturas <= 0) {
        cout << "Número de asignaturas inválido." << endl;
        return 1;
    }
    
    // Declaración del vector bidimensional (uso de vector de vectores para manejar dinámicamente el tamaño)
    vector<vector<double>> calificaciones(n, vector<double>(asignaturas));
    
    // Ingresar calificaciones
    ingresarCalificaciones(calificaciones, n, asignaturas);
    
    // Calcular promedios y extremos
    double promedioGeneral = calcularPromedioGeneral(calificaciones, n, asignaturas);
    double maxima, minima;
    encontrarMaxMin(calificaciones, n, asignaturas, maxima, minima);
    
    cout << "Registro de calificaciones del grupo:" << endl;
    
    // Imprimir el promedio individual de cada estudiante
    for (int i = 0; i < n; i++) {
        double promEstudiante = calcularPromedioEstudiante(calificaciones[i], asignaturas);
        cout << "Promedio del estudiante " << (i + 1) << ": " << fixed << setprecision(2) << promEstudiante << endl;
    }
    
    cout << "Promedio general del grupo: " << fixed << setprecision(2) << promedioGeneral << endl;
    cout << "Calificación máxima: " << fixed << setprecision(2) << maxima << endl;
    cout << "Calificación mínima: " << fixed << setprecision(2) << minima << endl;
    
    // Guardar los resultados en el archivo de texto
    guardarResultados(calificaciones, n, asignaturas, promedioGeneral, maxima, minima);
    
    return 0;
}