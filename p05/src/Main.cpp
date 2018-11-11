#include <iostream>
#include "../include/Lenguaje.hpp"
#include "../include/Menu.hpp"

using namespace std;

void inicializar(Lenguaje& l) {
    cout << "L" << l.get_id() << " = ";
    string str = "";
    cin >> str;
    l.definir(str);
    cout << l << endl;
}

int main() {

    Menu::mostrar();

    int opcion = 0;

    cin >> opcion;

    Lenguaje l1(1), l2(2), l3(3);

    switch(opcion) {
        case 1:
            inicializar(l1);
            l3 = l1.inversa();
            cout << "L" << l1.get_id() 
                << "^-1 = " << l3 << endl;
            break;

        case 2: 
            inicializar(l1);
            inicializar(l2);
            l3 = l1*l2;
            cout << "L" << l1.get_id() << " * " << "L" 
                << l2.get_id() << " = " << l3 << endl;                
            break;

        case 3: 
            inicializar(l1);
            inicializar(l2);
            l3 = l1.lunion(l2);
            cout << "L" << l1.get_id() << " U " << "L" 
                << l2.get_id() << " = " << l3 << endl;                
            break;

        case 4: 
            inicializar(l1);
            inicializar(l2);
            l3 = l1.interseccion(l2);
            cout << "L" << l1.get_id() << " ∩ " << "L" 
                << l2.get_id() << " = " << l3 << endl;                
            break;

        case 5: 
            inicializar(l1);
            inicializar(l2);
            l3 = l1 - l2;
            cout << "L" << l1.get_id() << " - " << "L" 
                << l2.get_id() << " = " << l3 << endl;                
            break;
    }

    return 0;
}

