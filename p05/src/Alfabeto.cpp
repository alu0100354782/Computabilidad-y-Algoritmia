#include "../include/Alfabeto.hpp"

Alfabeto::Alfabeto() {

}

Alfabeto::~Alfabeto() {

}

Alfabeto::Alfabeto(const Alfabeto &alfabeto) {
    *this = alfabeto;
}



const std::set<char>& Alfabeto::getSimbolos() {
    return _simbolos;
}

void Alfabeto::setSimbolos(const std::set<char> &simbolos) {
    _simbolos = simbolos;
}

void Alfabeto::insertar(const char &simbolo) {
    _simbolos.insert(simbolo);
}

const int Alfabeto::size() {
    return _simbolos.size();
}