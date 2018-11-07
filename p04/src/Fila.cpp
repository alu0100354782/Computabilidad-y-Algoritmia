#include "../include/Fila.hpp"

Fila::Fila() { _longitud = 0; }

Fila::Fila(const Fila &fila) {
    *this = fila;
}

Fila::~Fila() { }

const int& Fila::getLongitud() {
    return _longitud;
}

void Fila::ponerBloque(const int &nFila, Bloque &b) {
    _bloques.push_back(b);
    _longitud += b.getAncho();
    _nFila = nFila;
}

const std::vector<Bloque>& Fila::getBloques() {
    return _bloques;
}

bool Fila::operator==(const Fila &fila) {    
    return *this == fila;
}

std::ostream& operator<< (std::ostream& os, Fila &fila) {
    
    for(Bloque b : fila._bloques)
        os << b;

    os << "|";

    return os;    
}