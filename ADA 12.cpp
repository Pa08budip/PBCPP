#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    char tecla;
    double total;
    cout << "Monto a pagar: $" << endl;
    cin >> total;

    //(sembrador srand) generador de números según la hora del equipo
    srand(time(NULL));
    cout << "Presione cualquier tecla para tirar los dados." << endl;
    cin >> tecla;
    int dado1 = rand() % (6-1+1)+1;
    cout << "Dado 1: " << dado1 << endl;
    int dado2 = rand() % (6-1+1)+1;
    cout << "Dado 2: " << dado2 << endl;
    
    double total_desc;
   while (dado1==dado2){
        cout << "Caras Iguales."<< endl;
        cout << "Tire de nuevo los dados." << endl;
        cin >> tecla;
        dado1 = rand() % (6-1+1)+1;
        dado2 = rand() % (6-1+1)+1;
        cout << "Dado 1: " << dado1 << endl;
        cout << "Dado 2: " << dado2 << endl;
    }
    int suma = dado1 + dado2;
    if (suma==7){
        total_desc=total*0.75;
        cout << "Suma de los dados: " << suma << endl;
        cout << "FELICIDADES HA GANADO UN 25 POR CIENTO DE DESCUENTO" << endl;
        cout << "A su cuenta de: $" << total << " se le aplicara el descuento de: $" << (total-total_desc) << endl;
        cout << "Su total a pagar es de: $" << total_desc << endl;
    } else if (suma==9) {
        total_desc=total*0.85;
        cout << "Suma de los dados: " << suma << endl;
        cout << "FELICIDADES HA GANADO UN 15 POR CIENTO DE DESCUENTO" << endl;
        cout << "A su cuenta de: $" << total << " se le aplicara el descuento de: $" << (total-total_desc) << endl;
        cout << "Su total a pagar es de: $" << total_desc << endl;
    } else if (suma==11) {
        cout << "Suma de los dados: " << suma << endl;
        cout << "FELICIDADES HA GANADO UN CUPON CON EL 25 POR CIENTO DE DESCUENTO PARA SU PROXIMA VISITA." << endl;
        cout << "Su total a pagar es de: $" << total << endl;
    } else {
        cout << "Suma de los dados: " << suma << endl;
        cout << "AGRADECEMOS SU VISITA Y PREFERENCIA." << endl;
        cout << "Su total a pagar es de: $" << total << endl;
    }
    
    return 0;
}