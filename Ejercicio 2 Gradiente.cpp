#include <iostream>
#include <cmath>
using namespace std;

double f ( double x ) { return pow(x, 4) - 3 * std::pow(x, 3) + 2; }
double df ( double x ) { return 4 * pow(x, 3) - 9 * pow(x, 2); } // derivada
int main () {
double x = 4.0; // punto inicial
double alpha = 0.01; // tasa de a p r e n d i z a j e
double tol = 1e-6; // tol eran cia
int maxIter = 1000;
for (int k = 0; k < maxIter; ++k) {
    double g = df(x);
    if (std::fabs(g) < tol) break;

    // Calculamos el posible siguiente punto
    double x_nuevo = x - alpha * g;

    // PROTECCIÓN: Si el valor de la función subió en lugar de bajar
    if (f(x_nuevo) > f(x)) {
        alpha = alpha / 2.0; // Reducimos la tasa de aprendizaje a la mitad
        // No avanzamos 'x' en esta iteración y repetimos el intento con el nuevo alpha
        continue; 
    }    // Si todo salió bien y bajó, aceptamos el movimiento
    x = x_nuevo;
}
std :: cout << " Minimo aproximado en x = " << x <<endl;
}