#include <iostream>

using namespace std;

int main(){
    int calif;
    cout << "Ingrese su calificacion en la escala del 0 al 100: ";
    cin >> calif;
    if (cin.fail()) {
            cout << "No es un numero valido."<< endl;
            return 1;
    }else if (calif>=90 and calif<=100) {
        cout << "Su calificacion es A (las calificaciones no se redondean)" << endl;
    } else if (calif>=80 and calif<=89) {
        cout << "Su calificacion es B (las calificaciones no se redondean)"<< endl;
    } else if (calif>=70 and calif<=79) {
            cout << "Su calificacion es C (las calificaciones no se redondean)"<< endl;
    } else if (calif>=60 and calif<=69) {
            cout << "Su calificacion es D (las calificaciones no se redondean)"<< endl;
    } else if (calif>=0 and calif<=59) {
            cout << "Su calificacion es F (las calificaciones no se redondean)"<< endl;
    } else {
            cout << "Calificacion no valida"<< endl;
    }
    return 0;
    }