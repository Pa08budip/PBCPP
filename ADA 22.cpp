#include <iostream>
#include <string> 

using namespace std;

// Estructura de datos para guardar nombre y correo
struct Persona {
    string nombre;
    string correo;
};

// Función que valida las reglas del correo 
bool esCorreoValido(const string& correo) {
    // Verificar si la cadena está vacía usando .empty()
    if (correo.empty()) {
        return false;
    }

    // Verificar que no contenga espacios en blanco usando .find()
    if (correo.find(' ') != string::npos || correo.find('\t') != string::npos) {
        return false;
    }

    // Verificar que no comience ni termine con '@' o '.' usando .at() y .back()
    char primerChar = correo.at(0);
    char ultimoChar = correo.back();
    if (primerChar == '@' || primerChar == '.' || ultimoChar == '@' || ultimoChar == '.') {
        return false;
    }

    // Verificar que contenga exactamente un símbolo '@' usando .find()
    size_t posArroba = correo.find('@');
    if (posArroba == string::npos) {
        return false; // No se encontró ningún '@'
    }

    // Buscar si existe un segundo '@' después de la posición del primero
    if (correo.find('@', posArroba + 1) != string::npos) {
        return false; // Existe más de un '@'
    }

    // Verificar que tenga al menos un punto después del '@' usando .find()
    size_t posPuntoDespues = correo.find('.', posArroba + 1);
    if (posPuntoDespues == string::npos) {
        return false; // No hay un punto tras el '@'
    }

    return true;
}

int main() {
    // Arreglo de 5 estructuras Persona
    Persona personas[5];
    cout << "Registra los nombres y correos: " << endl;
    // Llenado del arreglo con nombres y correos
    for (int i = 0; i < 5; i++) {
        cout << "\nIngrese el nombre de la persona " << (i + 1) << ": ";
        getline(cin, personas[i].nombre);

        string correoIngresado;
        bool correoValido = false;

        // Ciclo do-while que no finaliza hasta obtener un correo válido
        do {
            cout << "Ingrese el correo de " << personas[i].nombre << ": ";
            getline(cin, correoIngresado);

            correoValido = esCorreoValido(correoIngresado);

            if (!correoValido) {
                cout << "Correo invalido. Intente nuevamente." << endl;
            }
        } while (!correoValido);

        // Guardar el correo validado en la estructura
        personas[i].correo = correoIngresado;
    }

    cout << "Personas registradas:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << ". " << personas[i].nombre << " -> " << personas[i].correo << endl;
    }

    return 0;
}