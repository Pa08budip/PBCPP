#include <iostream>
#include <cmath>

int main() {
    // Datos de los puntos: (1, 2), (2, 4), (3, 6)[cite: 14]
    double x_datos[3] = {1.0, 2.0, 3.0};
    double y_datos[3] = {2.0, 4.0, 6.0};
    int n = 3;

    double m = 0.0, b = 0.0; // Empezamos suponiendo m=0 y b=0
    double alpha = 0.05;     // Tasa de aprendizaje
    double tol = 1e-6;
    int maxIter = 5000;

    for (int k = 0; k < maxIter; ++k) {
        double grad_m = 0.0;
        double grad_b = 0.0;

        // Calculamos la sumatoria para las derivadas parciales
        for (int i = 0; i < n; ++i) {
            double error = (m * x_datos[i] + b) - y_datos[i];
            grad_m += error * x_datos[i];
            grad_b += error;
        }

        grad_m = (2.0 / n) * grad_m;
        grad_b = (2.0 / n) * grad_b;

        // Criterio de parada
        if (std::fabs(grad_m) < tol && std::fabs(grad_b) < tol) break;

        // Actualizamos m y b
        m = m - alpha * grad_m;
        b = b - alpha * grad_b;
    }

    std::cout << "Recta ajustada: y = " << m << "x + " << b << "\n";
    return 0;
}