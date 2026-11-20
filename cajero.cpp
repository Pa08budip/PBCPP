#include <iostream>

using namespace std;

int main(){
    int opcion;
cout << "Seleccione una opcion:\n"
    << "1. Consultar saldo.\n"
    <<"2. Retirar.\n"
    <<"3. Depositar.\n";
cin >> opcion;
switch(opcion)
{
case 1:
    cout << "Tu saldo es...\n";
    break;
case 2:
    cout << "Ingrese la cantidad a retirar: \n";
    break;
case 3:
    cout << "Ingrese la cantidad a depositar: \n";
    break;
case 0:
    cout << "Saliendo del programa...\n";
    break;
    return 0;
default:
    cout << "Opcion no valida.\n";
    break;
}
    return 0;
}