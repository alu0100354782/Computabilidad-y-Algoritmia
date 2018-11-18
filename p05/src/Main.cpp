#include <iostream>
#include "../include/Lenguaje.hpp"
#include "../include/Menu.hpp"

using namespace std;

int main() {

    Menu::mostrar();

    int opcion = 0;

    cin >> opcion;

    Menu::operar(opcion);

    return 0;
}

