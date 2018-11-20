#include "../include/Transicion.hpp"

/**
 * @brief Constructor por defecto
 * Construct a new Transicion:: Transicion object
 * 
 */
Transicion::Transicion() { }

/**
 * @brief Constructor con parámetros
 * Construct a new Transicion:: Transicion object
 * 
 * @param simbolo 
 * @param hacia_estado 
 */
Transicion::Transicion(const char& simbolo, Estado* hacia_estado) {
    _hacia_estado = hacia_estado;
    _simbolo = simbolo;
}

/**
 * @brief Constructor de copia
 * Construct a new Transicion:: Transicion object
 * 
 * @param transicion 
 */
Transicion::Transicion(const Transicion& transicion) {
    *this = transicion;
}

/**
 * @brief Destroy the Transicion:: Transicion object
 * 
 */
Transicion::~Transicion() { }

/**
 * @brief Obtener Símbolo entrante de la Transición
 * 
 * @return const char& 
 */
const char& Transicion::get_simbolo() {
    return _simbolo;
}

/**
 * @brief Establecer Símbolo entrante de la Transición
 * 
 * @param simbolo 
 */
void Transicion::set_simbolo(const char& simbolo) {
    _simbolo = simbolo;
}

/**
 * @brief Obtener Estado hacia el que va la Transición
 * 
 * @return const Estado& 
 */
Estado* Transicion::get_hacia_estado() {
    return _hacia_estado;
}

/**
 * @brief Establecer Estado hacia el que va la Transición
 * 
 * @param hacia_estado 
 */
void Transicion::set_hacia_estado(Estado* hacia_estado) {
    _hacia_estado = hacia_estado;
}

Transicion& Transicion::operator = (const Transicion& transicion) {
    *this = transicion;
    return *this;
}

int Transicion::operator == (const Transicion& transicion) const {
    if(_simbolo != transicion._simbolo && _hacia_estado != transicion._hacia_estado)
        return 0;
    return 1;
}

int Transicion::operator < (const Transicion& transicion) const {
    if(_simbolo < transicion._simbolo && _hacia_estado < transicion._hacia_estado)
        return 0;
    return 1;
}

/**
 * @brief Sobre carga del operador de salida
 * 
 * @param os 
 * @param transicion 
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& os, const Transicion& transicion) {
    os << transicion._simbolo << " " << transicion._hacia_estado;
    return os;
}