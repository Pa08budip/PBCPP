#include <iostream>
using namespace std;

int main () {
    string nombre_completo, nombre ="",apellido="";
    int i, largo;
    bool llenarApellido = false;
    cout << "Ingrese su nombre completo: ";
    getline(cin, nombre_completo);
    largo = nombre_completo.length();
    for (i = 0; i < largo; i++) {
        if(llenarApellido){
            apellido+=nombre_completo[i];
        }else{
            if(nombre_completo[i] == ' '){
                llenarApellido = true;
            }else{
                nombre+=nombre_completo[i];
            }
        }
    }
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Largo del nombre completo: " << largo << endl;
    return 0;
}