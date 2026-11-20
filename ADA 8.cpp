#include <iostream>

using namespace std;

int main(){
    double lado1;
    cout << "Ingrese la dimension del lado 1: ";
    cin >> lado1;
    if (cin.fail()) {
            cout << "No es una dimension valida."<< endl;
            return 1;
    }
    if (lado1<=0) {
        cout << "No es una dimension valida."<< endl;
        return 0;
    }
    double lado2;
    cout << "Ingrese la dimension del lado 2: ";
    cin >> lado2;
    if (cin.fail()) {
            cout << "No es una dimension valida."<< endl;
            return 1;
    }
    if (lado2<=0) {
        cout << "No es una dimension valida."<< endl;
        return 0;
    }
    double lado3;
    cout << "Ingrese la dimension del lado 3: ";
    cin >> lado3;
    if (cin.fail()) {
            cout << "No es una dimension valida."<< endl;
            return 1;
    }
    if (lado1<=0) {
        cout << "No es una dimension valida."<< endl;
        return 0;
    }
    
    if (lado1==lado2 and lado1==lado3 and lado2==lado3) {
        cout << "El triangulo es equilatero" << endl;
    } else if (lado1==lado2 || lado1==lado3 || lado2==lado3) {
        cout << "El triangulo es isosceles"<< endl;
    } else if (lado1!=lado2 and lado1!=lado3 and lado2!=lado3) {
            cout << "El triangulo es escaleno"<< endl;
    } else {
            cout << "No es un triangulo"<< endl;
    }
    return 0;
}
    