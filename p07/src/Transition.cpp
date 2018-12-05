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
 * @param symbol símbolo con el que se transita
 * @param toState estado al que se transita
 */
Transition::Transition(char symbol, unsigned int toState) {
    this->symbol_ = symbol;
    this->toState_ = toState;
}

/**
 * @brief Construct a new Transition:: Transition object
 * Constructor de copia
 *
 * @param t Transición a copiar
 */
Transition::Transition(const Transition& t) {
    *this = t;
}

/**
 * @brief Destroy the Transition:: Transition object
 * Destructor
 * 
 */
Transition::~Transition() {}

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
 * @return const unsigned& Transition::gettoState Estado al que se transita
 */
const unsigned int& Transition::gettoState() {
    return this->toState_;
}

/**
 * @brief Establecer símbolo de la transición
 *
 * @param symbol Símbolo a establecer
 */
void Transition::setsymbol(char& symbol) {
    this->symbol_ = symbol;
}

/**
 * @brief Establecer estado al que va la transición
 *
 * @param toState Estado al que se transita
 */
void Transition::settoState(int& toState) {
    this->toState_ = toState;
}

/**
 * @brief Sobrecarga del operador =
 *
 * @param t Transición a asignar
 * @return Transition& Transición resultanto
 */
Transition& Transition::operator=(const Transition &t) {
   this->symbol_ = t.symbol_;
   this->toState_ = t.toState_;
   return *this;
}

/**
 * @brief Sobrecarga del operador ==
 *
 * @param t Transición a comparar con la actual
 * @return int 1 son iguales, 0 son distintas
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
 * @param t Transición a comparar con la actual
 * @return int 1 es menor o igual, 0 es mayor
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
 * @param transition Transición a mostrar
 * @return ostream& flujo de salida
 */
ostream& operator << (ostream& os, const Transition& transition) {
    os << transition.symbol_ << " " << transition.toState_ << " ";
    return os;
}
