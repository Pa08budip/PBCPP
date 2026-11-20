#include <iostream>

using namespace std;

int main(){
    char opcion;
cout << "Seleccione una operacion aritmetica:\n"
    << "+\n"
    << "-\n"
    << "*\n"
    << "/\n";
cin >> opcion;
double numero1;
double numero2;
cout << "Ingrese un numero: " << endl;
cin >> numero1;
if (cin.fail()) {
        cout << "No es un numero valido"<< endl;
        return 1;
    }
cout << "Ingrese otro numero: " << endl;
cin >> numero2;
if (cin.fail()) {
        cout << "No es un numero valido"<< endl;
        return 1;
    }
switch(opcion)
{
case '+':
    cout << "El resultado de la suma es: " << numero1 + numero2 << endl;
    break;
case '-':
    cout << "La diferencia es: " << numero1 - numero2 << endl;
    break;
case '*':
    cout << "El producto es: " << numero1 * numero2 << endl;
    break;
case '/':
    if (numero2 != 0) {
        cout << "El cociente es: " << numero1 / numero2 << endl;
    } else {
        cout << "Error: Division entre cero es un resultado indeterminado." << endl;
        return 0;
    }
    break;
default:
    cout << "Operacion no valida." << endl;
    break;
}
    return 0;
}