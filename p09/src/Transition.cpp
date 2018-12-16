/**
 * @file Transition.cpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @brief Funciones y métodos de la clase Transition
 * @version 0.1
 * @date 2018-12-16
 *
 * @copyright Copyright (c) 2018
 *
 */
#include "../include/Transition.hpp"

/**
 * @brief Construct a new Transition:: Transition object
 * Constructor por defecto
 *
 */
Transition::Transition() {}

/**
 * @brief Construct a new Transition:: Transition object
 *
 * @param symbol Símbolo con el que se transita
 * @param toState Estado al que se transita
 */
Transition::Transition(char symbol, unsigned int toState) {
    symbol_ = symbol;
    tostate_ = toState;
}

/**
 * @brief Construct a new Transition:: Transition object
 * Constructor de copia
 *
 * @param t
 */
Transition::Transition(const Transition& t) {
    *this = t;
}

/**
 * @brief Obtener símbolo de la transición
 *
 * @return const char& Símbolo de la transición
 */
const char& Transition::getsymbol() {
    return this->symbol_;
}

/**
 * @brief Obtener estado al que va la transición
 *
 * @return const unsigned& Transition::gettostate Estado al que se transita
 */
const unsigned int& Transition::gettostate() {
    return tostate_;
}

/**
 * @brief Establecer símbolo de la transición
 *
 * @param symbol Símbolo con el que se transita
 */
void Transition::setsymbol(char& symbol) {
    symbol_ = symbol;
}

/**
 * @brief Establecer estado al que va la transición
 *
 * @param toState Estado al que se transita
 */
void Transition::settostate(int& toState) {
    tostate_ = toState;
}

/**
 * @brief Sobrecarga del operador de asignación
 *
 * @param t Transición asignada
 * @return Transition& Transición a la que se asigna
 */
Transition& Transition::operator=(const Transition &t) {
   symbol_ = t.symbol_;
   tostate_ = t.tostate_;
   return *this;
}

/**
 * @brief Sobrecarga del operador ==
 *
 * @param t Transición a comparar
 * @return int 1 true, 0 false
 */
int Transition::operator==(const Transition &t) const {
  if(symbol_ != t.symbol_)
    return 0;

  if(tostate_ != t.tostate_)
    return 0;

  return 1;
}

/**
 * @brief Sobrecarga del operador <
 *
 * @param t Transición a comparar
 * @return int 1 true, 0 false
 */
int Transition::operator<(const Transition &t) const {
  if(symbol_ == t.symbol_ && tostate_ < t.tostate_)
    return 1;

  if(symbol_ < t.symbol_ )
    return 1;

  return 0;
}

/**
 * @brief Sobrecarga del operador de salida
 *
 * @param os Flujo de salida
 * @param transition
 * @return ostream& Cadena resultante
 */
ostream& operator << (ostream& os, const Transition& transition) {
    os << transition.symbol_ << " " << transition.tostate_ << " ";
    return os;
}
