#include <iostream>

using namespace std;

int main(){
    int numero;
    cout << "Introduce un numero: ";
    cin >> numero;
    if(cin.fail()) {
        cout << "No es un numero valido." << endl;
        return 1;
    }
    if (numero % 2 == 0) {
        cout << "El numero " << numero << " es par." << endl;
    } else {
        cout << "El numero " << numero << " es impar." << endl;
    }
    return 0;
}