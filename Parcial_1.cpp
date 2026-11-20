#include <iostream>
#include <string>
using namespace std;

int main(){
    //solicitar tipo de vehículo
    int vehiculo;
    cout << "Seleccione el tipo de vehiculo introduciendo el numero que corresponde: \n"
         << "1. Automovil\n"
         << "2. Motocicleta\n"
         << "3. Camion\n";
    cin >> vehiculo;
    //para validar que ingrese un numero y no otra variable
    if (cin.fail()) {
        cout << "Opcion no valida." << endl;
        return 1;
    }
    //solicitar numero de horas estacionado
    int horas;
    cout << "Ingrese el numero de horas estacionado: ";
    cin >> horas;
    //para validar que el numero de horas sea valido
    if ((cin.fail()) || (horas < 0)) {
        cout << "No son horas validas"<< endl;
        return 1;
    }
    //se calcula el costo del estacionamineto dependiendo de cada caso (tipo de vehículo y horas estacionado)
    switch(vehiculo)
    {
        case 1:
            if (horas>=5 && horas<=10)
            {
                cout << "Usted va a pagar: $" << horas * 30 * 0.9 << endl;
            }
            else if (horas>12)
            {
                cout << "Usted va a pagar: $" << horas * 30 * 1.15 << endl;
            }
            else
            {
            cout << "Usted va a pagar: $" << horas * 30 << endl;
            }
            break;
        case 2:
            if (horas>=5 && horas<=10)
            {
                cout << "Usted va a pagar: $" << horas * 15 * 0.9 << endl;
            }
            else if (horas>12)
            {
                cout << "Usted va a pagar: $" << horas * 15 * 1.15 << endl;
            }
            else
            {
            cout << "Usted va a pagar: $" << horas * 15 << endl;
            }
            break;
        case 3:
            if (horas>=5 && horas<=10)
            {
                cout << "Usted va a pagar: $" << horas * 50 * 0.9 << endl;
            }
            else if (horas>12)
            {
                cout << "Usted va a pagar: $" << horas * 50 * 1.15 << endl;
            }
            else
            {
            cout << "Usted va a pagar: $" << horas * 50 << endl;
            }
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }

    return 0;
}