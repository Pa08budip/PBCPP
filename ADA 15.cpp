#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
int main()
{
    char tecla;
    int suposición;
    int jugar = 1;
    srand(time(NULL));
    do
    {
        cout << "Presione cualquier tecla para iniciar el juego" << endl;
        cin >> tecla;
        int numero = rand() % 100 + 1;
        cout << "Adivine el numero (entre 1 y 100): " << endl;
        bool ganado = false; // Bandera para controlar si el usuario ganó
        for (int i = 0; i < 10; i++)
        {
            cin >> suposición;
            while (suposición < 1 || suposición > 100 || cin.fail())
            {
                //Sirve para limpiar la entrada de datos y evitar que se quede en un estado de error
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "El numero ingresado no es valido, intente nuevamente: ";
                cin >> suposición;
            }
            if (suposición == numero)
            {
                cout << "Felicidades, adivinaste el numero." << endl;
                ganado = true;
                break;
            }
            else if (suposición < numero)
            {
                cout << "El numero es mayor, intente nuevamente: ";
            }
            else
            {
                cout << "El numero es menor, intente nuevamente: ";
            }
        }
        if (!ganado)
        {
            cout << "Has perdido el juego. Se te acabaron los 10 intentos." << endl;
            cout << "El numero secreto era: " << numero << endl;
        }
        cout << "Desea jugar de nuevo? (1: Si, 0: No): ";
        cin >> jugar;

    } while (jugar == 1);
    
    cout << "Gracias por jugar." << endl;
    return 0;
}