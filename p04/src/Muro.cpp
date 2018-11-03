#include "../include/Muro.hpp"

Muro::Muro() { }
Muro::~Muro() { }

void Muro::setDimension(const int &largo, const int &ancho) {
    _largo = largo;
    _ancho = ancho;
}

const Fila& Muro::getFila(const int &i) {
    return _filas[i];
}

void Muro::setFila(const Fila &fila) {
    _filas.push_back(fila);
}

std::ostream& operator<< (std::ostream& os, Muro &muro) {
    for (Fila f : muro._filas) 
        os << f << std::endl;
    
    return os;
}