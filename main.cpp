#include <iostream>
#include <string>

int main(){
    
    std::string nombre;
    int edad;
    std::cout << "Por favor, introduce tu nombre: ";
    std::cin >> nombre;
    
    std::cout << "Introduce tu edad: ";
    std::cin >> edad;
    
    std::cout << "Hola," << nombre << ". Tienes" << edad <<" años." << std::endl;
    
    return 0;
}