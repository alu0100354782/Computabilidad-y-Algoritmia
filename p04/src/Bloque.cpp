#include "../include/Bloque.hpp"

Bloque::Bloque() { }

Bloque::Bloque(const Bloque& bloque) {
    *this = bloque;
}

Bloque::Bloque(const int& ancho) {
    _ancho = ancho;
}

Bloque::~Bloque() { }

const int& Bloque::getAncho() {
    return _ancho;
}

bool Bloque::operator==(const Bloque &bloque) {
    return _ancho == bloque._alto;
}

std::ostream& operator<< (std::ostream& os, Bloque &bloque) {
    if (bloque._ancho == 2)
        os << "|xx";
    if (bloque._ancho == 3)
        os << "|xxx";
    
    return os;
}