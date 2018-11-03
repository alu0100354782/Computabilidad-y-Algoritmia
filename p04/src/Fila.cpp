#include "../include/Fila.hpp"

Fila::Fila() { }
Fila::~Fila() { }

void Fila::ponerBloque(const int &sFila, const Bloque &b) {
    _bloques.push_back(b);
}

const std::vector<Bloque>& Fila::getBloques() {
    return _bloques;
}

std::ostream& operator<< (std::ostream& os, Fila &fila) {
    
    for(Bloque b : fila._bloques) {    
        os << b;
    }

    os << "|";

    return os;
    
}