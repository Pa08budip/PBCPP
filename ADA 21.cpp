#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
int main()
{
    cout << "Ingrese una frase o palabra: ";
    string palabra_original, palabra = "", palabra_invertida = "";
    getline(cin, palabra_original);

    for (char c : palabra_original)
    {
        if (isalpha(static_cast<unsigned char>(c)))
        {
            palabra += tolower(static_cast<unsigned char>(c));
        }
    }
    for (int i = palabra.length() - 1; i >= 0; i--)
    {
        palabra_invertida += palabra[i];
    }
    cout << "Palabra invertida: " << palabra_invertida << endl;

    //Hay que verificar que no esté vacío para que tampoco cuente como palíndromo una cadena vacía
    if (!palabra.empty() && palabra == palabra_invertida)
    {
        cout << "La palabra es un palindromo." << endl;
    }
    else
    {
        cout << "La palabra no es un palindromo." << endl;
    }

    return 0;
}