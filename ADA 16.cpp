#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char tecla;
    int jugar = 1;
    // Sembrador para el generador de números aleatorios
    srand(time(NULL));
    
    do
    {
        cout << "Presione cualquier tecla para tirar los dados" << endl;
        cin >> tecla;
        
        int dado1 = rand() % 6 + 1;
        cout << "Dado 1: " << dado1 << endl;
        int dado2 = rand() % 6 + 1;
        cout << "Dado 2: " << dado2 << endl;
        
        int suma = dado1 + dado2;
        cout << "Suma del primer tiro: " << suma << endl;

        // Evaluamos el primer tiro
        if (suma == 7 || suma == 11)
        {
            cout << "FELICIDADES, HAS GANADO EN EL PRIMER TIRO" << endl;
        }
        else if (suma == 2 || suma == 3 || suma == 12)
        {
            cout << "HAS SACADO UN CRAPS (2, 3 o 12). HAS PERDIDO." << endl;
        }
        else
        {
            int puntos_acumulados = 0;
            cout << "Punto establecido. Debe seguir tirando hasta acumular 7 puntos." << endl;
            cout << "Pierde si saca un 7 o un CRAPS (2, 3 o 12)." << endl;

            bool en_juego = true;
            
            while (en_juego)
            {
                cout << "Presione cualquier tecla para tirar los dados nuevamente" << endl;
                cin >> tecla;
                
                dado1 = rand() % 6 + 1;
                cout << "Dado 1: " << dado1 << endl;
                dado2 = rand() % 6 + 1;
                cout << "Dado 2: " << dado2 << endl;
                
                int suma_tiro = dado1 + dado2;
                cout << "Suma de los dados: " << suma_tiro << endl;

                // Verificamos si pierde en los tiros subsiguientes
                if (suma_tiro == 7)
                {
                    cout << "HAS SACADO UN 7. HAS PERDIDO EL JUEGO." << endl;
                    en_juego = false;
                }
                else if (suma_tiro == 2 || suma_tiro == 3 || suma_tiro == 12)
                {
                    cout << "HAS SACADO UN CRAPS (2, 3 o 12). HAS PERDIDO." << endl;
                    en_juego = false;
                }
                else
                {
                    // Tiro válido: sumamos 1 punto al contador correctamente
                    puntos_acumulados++;
                    cout << "Tiro válido. Puntos acumulados: " << puntos_acumulados << " / 7" << endl;

                    // Condicional para validar si ya acumula 7 puntos y gana el juego
                    if (puntos_acumulados >= 7)
                    {
                        cout << "FELICIDADES, HAS ACUMULADO 7 PUNTOS. HAS GANADO EL JUEGO" << endl;
                        en_juego = false;
                    }
                }
            }
        }

        cout << "Desea jugar de nuevo? (1: Si, 0: No): ";
        cin >> jugar;

    } while (jugar == 1);

    cout << "Gracias por jugar" << endl;
    return 0;
}