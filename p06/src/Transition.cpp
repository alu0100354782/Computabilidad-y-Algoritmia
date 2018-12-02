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
 * @param symbol 
 * @param toState 
 */
Transition::Transition(char symbol, unsigned int toState) {
    this->symbol_ = symbol;
    this->toState_ = toState;
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
 * @return const char& 
 */
const char& Transition::getsymbol() {
    return this->symbol_;
}

/**
 * @brief Obtener estado al que va la transición
 * 
 * @return const unsigned& Transition::gettoState 
 */
const unsigned int& Transition::gettoState() {
    return this->toState_;
}

/**
 * @brief Establecer símbolo de la transición
 * 
 * @param symbol 
 */
void Transition::setsymbol(char& symbol) {
    this->symbol_ = symbol;
}

/**
 * @brief Establecer estado al que va la transición
 * 
 * @param toState 
 */
void Transition::settoState(int& toState) {
    this->toState_ = toState;
}

/**
 * @brief Sobrecarga del operador =
 * 
 * @param t 
 * @return Transition& 
 */
Transition& Transition::operator=(const Transition &t) {
   this->symbol_ = t.symbol_;
   this->toState_ = t.toState_;
   return *this;
}

/**
 * @brief Sobrecarga del operador ==
 * 
 * @param t 
 * @return int 1 true, 0 false
 */
int Transition::operator==(const Transition &t) const {
  if( this->symbol_ != t.symbol_)
    return 0;

  if( this->toState_ != t.toState_)
    return 0;

  return 1;
}

/**
 * @brief Sobrecarga del operador <
 * 
 * @param t 
 * @return int 1 true, 0 false
 */
int Transition::operator<(const Transition &t) const {
  if( this->symbol_ == t.symbol_ && this->toState_ < t.toState_)
    return 1;

  if( this->symbol_ < t.symbol_ )
    return 1;

  return 0;
}

/**
 * @brief Sobrecarga del operador de salida
 * 
 * @param os Cadena resultante
 * @param transition 
 * @return ostream& 
 */
ostream& operator << (ostream& os, const Transition& transition) {
    os << transition.symbol_ << " " << transition.toState_ << " ";
    return os;
}
