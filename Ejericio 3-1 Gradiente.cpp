#include <iostream>
#include <cmath>

double f(double x, double y) {
    return (x - 1) * (x - 1) + 2 * (y + 2) * (y + 2);
}

// Derivadas parciales del gradiente
double df_dx(double x) { return 2 * (x - 1); }
double df_dy(double y) { return 4 * (y + 2); }

int main() {
    double x = 0.0, y = 0.0; // Punto inicial (0, 0)
    double alpha = 0.1;      // Tasa de aprendizaje
    double tol = 1e-6;
    int maxIter = 1000;

    for (int k = 0; k < maxIter; ++k) {
        double gx = df_dx(x);
        double gy = df_dy(y);

        // Criterio de parada: ambas pendientes deben ser casi cero
        if (std::fabs(gx) < tol && std::fabs(gy) < tol) break;

        // Actualizamos ambas variables simultáneamente
        x = x - alpha * gx;
        y = y - alpha * gy;
    }

    std::cout << "Minimo encontrado en: (" << x << ", " << y << ")\n";
    std::cout << "Valor de f(x, y) = " << f(x, y) << "\n";
    return 0;
}