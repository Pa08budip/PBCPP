#include <iostream>
#include <string>

using namespace std;

int main(){
    
    double radio;
    cout << "Introduce el radio: ";
    cin >> radio;
    
    float area;
    area = 3.14*radio*radio;
    
    float circunferencia;
    circunferencia = 3.14*2*radio;
    
    cout << "El area es: " << area << std::endl;
    cout << "La circunferencia es: " << circunferencia << std::endl;
    
    return 0;
}