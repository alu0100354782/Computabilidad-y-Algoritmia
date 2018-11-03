#include <iostream>
#include "../include/Muro.hpp"

#define L2 2
#define L3 3

using namespace std;

int main() {

    Bloque b(L2);
    Fila f;
    
    for(int i=0;i<4;i++) {
        f.ponerBloque(i, b);
    }

    Muro m;
    m.setFila(f);
    m.setFila(f);

    cout << m << endl;

    return 0;
}