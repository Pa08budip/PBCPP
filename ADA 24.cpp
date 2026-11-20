#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pelicula {
    string titulo;
    string director;
    int año;
    int duracion;
};

int main() {
    vector<Pelicula> catalogo;
    int opcion = 0;

    do {
        cout << "\nMENU DE CATALOGO DE PELICULAS" << endl;
        cout << "1. Agregar una pelicula" << endl;
        cout << "2. Visualizar todas las peliculas" << endl;
        cout << "3. Eliminar una pelicula" << endl;
        cout << "4. Buscar y mostrar una pelicula especifica" << endl;
        cout << "5. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer despues de leer un numero

        switch (opcion) {
            case 1: { // Agregar una pelicula
                Pelicula p;
                cout << "\nTitulo: ";
                getline(cin, p.titulo);
                cout << "Director: ";
                getline(cin, p.director);
                cout << "Año: ";
                cin >> p.año;
                cout << "Duracion (minutos): ";
                cin >> p.duracion;
                cin.ignore(); // Limpiar el buffer

                catalogo.push_back(p);
                cout << "Pelicula agregada correctamente." << endl;
                break;
            }
            case 2: { // Visualizar todas las peliculas
                cout << "\nCATALOGO DE PELICULAS" << endl;
                if (catalogo.size() == 0) {
                    cout << "No hay peliculas registradas." << endl;
                } else {
                    for (int i = 0; i < catalogo.size(); i++) {
                        cout << "Titulo: " << catalogo[i].titulo << endl;
                        cout << "Director: " << catalogo[i].director << endl;
                        cout << "Año: " << catalogo[i].año << endl;
                        cout << "Duracion: " << catalogo[i].duracion << " minutos" << endl;
                    }
                }
                break;
            }
            case 3: { // Eliminar una pelicula
                cout << "\nIngrese el titulo de la pelicula a eliminar: ";
                string dato;
                getline(cin, dato);

                bool eliminada = false;
                for (int i = 0; i < catalogo.size(); i++) {
                    if (catalogo[i].titulo == dato) {
                        catalogo.erase(catalogo.begin() + i);
                        cout << "Pelicula eliminada." << endl;
                        eliminada = true;
                        break;
                    }
                }
                if (!eliminada) {
                    cout << "No se encontro la pelicula." << endl;
                }
                break;
            }
            case 4: { // Buscar y mostrar una pelicula
                cout << "\nIngrese el titulo de la pelicula a buscar: ";
                string dato;
                getline(cin, dato);

                bool encontrada = false;
                for (int i = 0; i < catalogo.size(); i++) {
                    if (catalogo[i].titulo == dato) {
                        cout << "\nPelicula encontrada:" << endl;
                        cout << "Titulo: " << catalogo[i].titulo << endl;
                        cout << "Director: " << catalogo[i].director << endl;
                        cout << "Año: " << catalogo[i].año << endl;
                        cout << "Duracion: " << catalogo[i].duracion << " minutos" << endl;
                        encontrada = true;
                        break;
                    }
                }
                if (!encontrada) {
                    cout << "Pelicula no encontrada." << endl;
                }
                break;
            }
            case 5: { // Salir
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
            }
        }

    } while (opcion != 5);

    return 0;
}