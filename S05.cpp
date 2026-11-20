#include <iostream>

using namespace std;

int main(){
    int saldo = 100;
    cout << "Saldo inicial: $" << saldo << endl;
    saldo += 50;
    cout << "Saldo despues de deposito: $" << saldo << endl;
    saldo-=25;
    cout << "Saldo despues de retiro: $" << saldo << endl;
    return 0;
}