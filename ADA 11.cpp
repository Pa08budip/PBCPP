#include <iostream>

using namespace std;

int main(){
    //Declarar variable dia y solicitar al usuario que proporcione el dia
    int dia;
    cout << "Proporcione el dia utilizando 2 digitos: ";
    cin >> dia;
    if ((cin.fail()) || (dia<01)) {
        cout << "No es un dia valido"<< endl;
        return 1;
    }
    //Declarar variable mes y solicitar al usuario que proporcione el mes
    int mes;
    cout << "Proporcione el mes utilizando 2 digitos: ";
    cin >> mes;
    //Validar mes
    if ((cin.fail()) || (mes>12 || mes<01)) {
        cout << "No es un mes valido"<< endl;
        return 1;
    }
    //Declarar variable año y solicitar al usuario que proporcione el año
    int año;
    cout << "Proporcione el ano: ";
    cin >> año;
    //Validar año
    if ((cin.fail()) || (año<=0)) {
        cout << "No es un año valido"<< endl;
        return 1;
    }
//Validar año bisiesto si es divisible entre 4 y no es divisible entre 100 o si es divisible entre 400
bool bisiesto = false;
    if (año%4==0 && año%100!=0 || año%400==0){
        bisiesto = true;
    }
    if (bisiesto){
        cout << "El ano es bisiesto" << endl;
    }  
    //Validar mes de febrero en año bisiesto
    if (bisiesto && mes==02 && (dia>29 || dia<01)){
        cout << "No es una fecha valida (dia invalido)" << endl;
        return 1;
        }
    //Validar mes de febrero
    else if (not(bisiesto) && mes==02 && (dia>28 || dia<01)){
        cout << "No es una fecha valida (dia invalido)" << endl;
        return 1;
        }
    //Validar meses con 31 dias
    else if ((mes==01 || mes==03 || mes==05 || mes==07 || mes==8 || mes==10 || mes==12) && (dia>31)){
        cout << "No es una fecha valida (dia invalido)" << endl;
        return 1;
        }
    //Validar meses con 30 dias
    else if ((mes==04 || mes==06 || mes==9 || mes==11) && (dia>30)){
        cout << "No es una fecha valida (dia invalido)" << endl;
        return 1;
        }
    //Si pasa todas las validaciones
    else{
        cout << "Es una fecha valida" << endl;
    }
    return 0;
}