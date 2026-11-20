#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double h_inicial;
    cout << "Altura inicial en metros:";
    cin >> h_inicial;
    if (h_inicial < 0) {
        cout << "La altura inicial no puede ser negativa. Por favor ingrese una altura valida." << endl;
        return 1;
    }
    if(cin.fail()) {
        cout << "No es una altura valida." << endl;
        return 1;
    }
    if (h_inicial == 0) {
        cout << "No hay caida libre." << endl;
        return 0;
    }
    
    double gravedad = 9.81;
    double tiempo = sqrt(2 * h_inicial / gravedad);
    double velocidad = gravedad * tiempo;
    cout << "La velocidad de caida es de " << velocidad << " m/s en un tiempo de " << tiempo << " segundos." << endl;
    
    if (h_inicial > 100 && tiempo > 4) {
        cout << "Fue una caida peligrosa " << endl;
        return 0;
    }
    if (h_inicial < 5 || velocidad < 5) {
        cout << "Fue una caida segura " << endl;
        return 0;
    }

    if (velocidad < 10) {
        cout << "El impacto fue suave." << endl;
        return 0;
    }
    if (velocidad > 10 && velocidad < 30) {
        cout << "El impacto fue moderado." << endl;
        return 0;
    }
    if (velocidad > 30) {
        cout << "El impacto fue fuerte." << endl;
        return 0;
    }
    return 0;
}