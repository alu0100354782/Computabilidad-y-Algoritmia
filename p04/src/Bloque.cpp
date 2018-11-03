#include "../include/Bloque.hpp"

Bloque::Bloque(const int& size) {
    _size = size;
}

Bloque::~Bloque() { }

const int& Bloque::getSize() {
    return _size;
}

std::ostream& operator<< (std::ostream& os, Bloque &bloque) {
    if (bloque._size == 2)
        os << "|xx";
    if (bloque._size == 3)
        os << "|xxx";
    
    return os;
}