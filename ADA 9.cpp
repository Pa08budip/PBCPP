#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int horas_trabajadas;
    cout << "Ingrese las horas trabajadas: ";
    cin >> horas_trabajadas;
    if (cin.fail()) {
        cout << "No son horas validas"<< endl;
        return 1;
    }
    if (horas_trabajadas<0) {
        cout << "No son horas validas"<< endl;
        return 1;
    }
    
    int salario;
    if (horas_trabajadas<=40) {
        salario=horas_trabajadas*125;
    } else if (horas_trabajadas>=41 and horas_trabajadas<=48)
    {
        salario=((horas_trabajadas-40)*250)+5000;
    } else if (horas_trabajadas>48)
    {
        salario=((horas_trabajadas-48)*375)+7000;
    }
    
    if (salario>3500) {
        int base_ISR=salario-3500;
        double ISR=base_ISR*0.13;
        double salario_final=salario-ISR;
        printf("El total a pagar segun las horas trabajadas es de: %.2f\n", salario_final);
    } else {
        cout << "El total a pagar segun las horas trabajadas es de: " << salario << endl;
    }
    return 0;
}