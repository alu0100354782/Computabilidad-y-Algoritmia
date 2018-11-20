#include "../include/Estado.hpp"

/**
 * @brief Constructor por defecto
 * 
 */
Estado::Estado() { }

/**
 * @brief Constructor de copia
 * 
 */
Estado::Estado(const Estado& estado) {
    *this = estado;
 }

/**
 * @brief Destructor
 * 
 */
Estado::~Estado() { }

/**
 * @brief Obtener id del estado
 * 
 * @return const unsigned& Estado::get_id 
 */
const unsigned int& Estado::get_id() { 
    return _id;
}

/**
 * @brief Establecer id del estado
 * 
 * @param int 
 */
void Estado::set_id(const unsigned int& id){ 
    _id = id;
}

/**
 * @brief Obtener tipo de estado
 * 1 Aceptación; 0 No aceptación
 * 
 * @return const unsigned& Estado::get_tipo 
 */
const unsigned int& Estado::get_tipo() { 
    return _tipo;
}

/**
 * @brief Establecer tipo de estado
 * 1 Aceptación; 0 No aceptación
 * 
 * @param int 
 */
void Estado::set_tipo(const unsigned int& tipo) { 
    _tipo = tipo;
}

/**
 * @brief Obtener conjunto de transiciones
 * 
 * @return const std::set<Transicion>& 
 */
const std::set<Transicion>& Estado::get_transiciones() { 
    return _transiciones;
}

/**
 * @brief Establecer conjunto de transiciones
 * 
 */
void Estado::set_transiciones(const std::set<Transicion>& transiciones) { 
    _transiciones = transiciones;
}

/**
 * @brief Insertar transición al conjunto de transiciones
 * 
 */
void Estado::insertar_transicion(Transicion& transicion) { 
    _transiciones.insert(transicion);
}

/**
 * @brief Comprobar si es un estado de muerte (true)
 * 
 * @return true 
 * @return false 
 */
const bool Estado::es_estado_de_muerte() { 
    if(_transiciones.size() == 0)
        return true;

    for(Transicion t: _transiciones) {
        if(t.get_hacia_estado() != *this || _tipo == 1)
            return false;
    }

    return true;
}

/**
 * @brief Sobrecarga del operador ==
 * 1 si se cumple la igualdad
 * 
 * @return int 
 */
int Estado::operator == (const Estado& estado) const { 
    if(_id != estado._id )  return 0;
    return 1;
}

/**
 * @brief Sobrecarga del operador !=
 * 1 si se cumple la desigualdad
 * 
 * @return int 
 */
int Estado::operator != (const Estado& estado) const {
    if(_id == estado._id )  return 0;
    return 1;
}

/**
 * @brief Sobrecarga del operador <
 * 1 si es menor
 * 
 * @return int 
 */
int Estado::operator < (const Estado& estado) const { 
    if(_id < estado._id)    return 1;
    return 0;
}

/**
 * @brief Sobrecarga del operador de salida
 * 
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& os, const Estado& estado) { 
    os << estado._id << estado._tipo << estado._transiciones.size();

    for(Transicion t: estado._transiciones)
        os << t;

    return os;
}