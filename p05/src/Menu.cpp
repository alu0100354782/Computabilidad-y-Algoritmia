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

void Menu::operar(const int& opcion) {
    Lenguaje l1(1), l2(2), l3(3);

    switch(opcion) {
        case 1:
            inicializar(l1);
            l3 = l1.inversa();
            std::cout << "L" << l1.get_id() 
                << "^-1 = " << l3 << std::endl;
            break;

        case 2: 
            inicializar(l1);
            inicializar(l2);
            l3 = l1*l2;
            std::cout << "L" << l1.get_id() << " * " << "L" 
                << l2.get_id() << " = " << l3 << std::endl;                
            break;

        case 3: 
            inicializar(l1);
            inicializar(l2);
            l3 = l1.lunion(l2);
            std::cout << "L" << l1.get_id() << " U " << "L" 
                << l2.get_id() << " = " << l3 << std::endl;                
            break;

        case 4: 
            inicializar(l1);
            inicializar(l2);
            l3 = l1.interseccion(l2);
            std::cout << "L" << l1.get_id() << " ∩ " << "L" 
                << l2.get_id() << " = " << l3 << std::endl;                
            break;

        case 5: 
            inicializar(l1);
            inicializar(l2);
            l3 = l1 - l2;
            std::cout << "L" << l1.get_id() << " - " << "L" 
                << l2.get_id() << " = " << l3 << std::endl;                
            break;

        case 6: 
            inicializar(l1);
            inicializar(l2);
            std::cout << "L" << l2.get_id();
            if(l1.sublenguaje(l2))
                std::cout << " es sublenguaje de L";
            else
                std::cout << " NO es sublenguaje en L";
            std::cout << l1.get_id() << std::endl; 
            
            break;
        
        case 7: 
            inicializar(l1);
            inicializar(l2);
            std::cout << "L" << l2.get_id();
            if(l1 == l2)
                std::cout << " = L";
            else
                std::cout << " != L";
            std::cout << l1.get_id() << std::endl; 
            break;            

        case 8: {
            inicializar(l1);
            std::cout << "introduzca exponente:";
            int exponente = 0;
            std::cin >> exponente;
            l2 = l1.potencia(exponente);
            std::cout << "L" << l1.get_id() << "^" << exponente 
                << " = " << l2 << std::endl;                
            break;
        }
        case 9: 
            inicializar(l1);
            l2 = l1.kleene();
            std::cout << "L" << l1.get_id() << "* = " << l2 << std::endl;                
            break;
        
        default:
            break;
        
    }    
}

void Menu::inicializar(Lenguaje& l) {
    std::cout << "L" << l.get_id() << " = ";
    std::string str = "";
    std::cin >> str;
    l.definir(str);    
    std::cout << l << std::endl;
}
