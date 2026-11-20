#include <iostream>

using namespace std;

int main(){
    double costo_total;
    cout << "Introduce el costo total: ";
    cin >> costo_total;
    double costo_total_descuento = costo_total * 0.9;
    cout << "El costo total con descuento es de: $" << costo_total_descuento << endl;
    int cantidad_personas;
    cout << "Introduce la cantidad de personas que pagaran: ";
    cin >> cantidad_personas;
    double costo_por_persona = costo_total_descuento / cantidad_personas;
    int costo_personas_redondeado = static_cast<int>(costo_por_persona + 0.5);
    cout << "Costo por persona (redondeado): $" << costo_personas_redondeado << endl;
    int residuo;
    residuo = static_cast<int>(costo_total_descuento) % cantidad_personas;
    cout << "El residuo es de: $" << residuo << endl;
    cout << "La cantidad total a pagar con descuento incluido es de $" << costo_total_descuento << " y cada persona debera pagar $" << costo_personas_redondeado << ". Dando como residuo $" << residuo << "." << endl;
    return 0;
}