#include "../include/Menu.hpp"

void Menu::mostrar() {
    std::cout << std::endl << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << "|                                                  |" << std::endl;
    std::cout << "| COMPUTABILIDAD Y ALGORITMIA                      |" << std::endl;
    std::cout << "|                                                  |" << std::endl;
    std::cout << "| Sergio Reyes de León                             |" << std::endl;
    std::cout << "|                                                  |" << std::endl;
    std::cout << "| Práctica #05: Calculadora para lenguajes finitos |" << std::endl;
    std::cout << "|                                                  |" << std::endl;
    std::cout << "****************************************************" << std::endl << std::endl;
    std::cout << "\t 1.  Inversa" << std::endl;
    std::cout << "\t 2.  Concatenación" << std::endl;
    std::cout << "\t 3.  Unión" << std::endl;
    std::cout << "\t 4.  Intersección" << std::endl;
    std::cout << "\t 5.  Diferencia" << std::endl;
    std::cout << "\t 6.  Sublenguajes" << std::endl;
    std::cout << "\t 7.  Igualdad de lenguajes" << std::endl;
    std::cout << "\t 8.  Potencia"  << std::endl;
    std::cout << "\t 9.  Cierre de Kleene" << std::endl;
    std::cout << "\t 10. Salir" << std::endl << std::endl;

    std::cout << ">>> Introduzca una opción:  ";
}
