#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Posicion a consultar de la serie Fibonacci: ";
    cin >> n;
    if (n <= 0) {
        cout << "Por favor, ingrese un numero positivo y mayor que 0." << endl;
        return 1;
    }
    int a = 1;
    int b = 1;

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << a;
        int siguiente = a + b;
        a = b;
        b = siguiente;
    }
    cout << endl;
    return 0;
}