#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numero;
    /*Solicitar al usuario que ingrese un número positivo y mientras no se cumpla la condición, 
    se sigue solicitando*/
    do
    {
        cout << "Ingrese un numero: ";
        cin >> numero;
        if (numero <= 0 || cin.fail())
        {
            //Sirve para limpiar la entrada de datos y evitar que se quede en un estado de error
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "El numero ingresado no es valido, intente nuevamente." << endl;
        }
    } while (numero <= 0 || cin.fail());
    /*Sino se evalua si es primo o no, para ello se recorre un ciclo desde 2 hasta la raíz cuadrada 
    del número ingresado, si el número es divisible por alguno de los números del ciclo, entonces no es primo*/
        bool esPrimo = true;
        for (int i = 2; i <= sqrt(numero); i=i+1)
        {
            /*En caso que resukte que el número es divisible por alguno de los números del ciclo, 
            se cambia el valor de la variable esPrimo a false y se sale del ciclo con un break*/
            if (numero % i == 0)
            {
                esPrimo = false;
                break;
            }
        }
        if (esPrimo)
        {
            cout << numero << " es primo." << endl;
        }
        else
        {
            cout << numero << " no es primo." << endl;
        }
    return 0;
}