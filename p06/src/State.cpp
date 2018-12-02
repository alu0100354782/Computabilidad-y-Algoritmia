#include "../include/State.hpp"

/**
 * @brief Construct a new State:: State object
 * Constructor por defecto
 * 
 */
State::State() {}

/**
 * @brief Construct a new State:: State object
 * Constructor de copia
 * 
 * @param state 
 */
State::State(const State& state) {
    *this = state;
}

/**
 * @brief Destroy the State:: State object
 * Destructor
 */
State::~State() {
    transitions_.clear();
}

/**
 * @brief Obtener el identificador del estado
 * 
 * @return const unsigned& State::getn 
 */
const unsigned int& State::getn() {
    return this->n_;
}

/**
 * @brief Obtener tipo de estado, 
 * si es 1 es de aceptación
 * 
 * @return const unsigned& State::gettype 
 */
const unsigned int& State::gettype()  {
    return this->type_;
}

/**
 * @brief Obtener nº de transiciones del estado
 * 
 * @return const unsigned& State::getntransitions 
 */
const unsigned int& State::getntransitions() {
    return this->ntransitions_;
}

/**
 * @brief Obtener el conjunto de transiciones del estado
 * 
 * @return const set<Transition>& 
 */
const set<Transition>& State::gettransitions() {
    return this->transitions_;
}

/**
 * @brief Establecer identificador del estado
 * 
 * @param int 
 */
void State::setn(unsigned int& n) {
    this->n_ = n;
}

/**
 * @brief Establecer tipo de estado
 * 
 * @param int 1 aceptación, 0 no aceptación
 */
void State::settype(unsigned int& type) {
    this->type_ = type;
}

/**
 * @brief Establecer nº de transiciones
 * 
 * @param int nº de transiciones
 */
void State::setntransitions(unsigned int& ntransitions) {
    this->ntransitions_ = ntransitions;
}

/**
 * @brief Insertar transición
 * 
 * @param t transición
 */
void State::inserttransitions(Transition& t) {
    this->transitions_.insert(t);
}

/**
 * @brief Comprobar si es un estado de muerte
 * 
 * @return true 
 * @return false 
 */
bool State::deadstate() {
    if (transitions_.size() == 0)
      return true;

    for(int i = 0; i < this->transitions_.size(); i++) {
        
        set<Transition>::iterator it = transitions_.begin();
        advance(it, i);
        Transition x = *it;

        if(x.gettoState() != n_) {
            return false;
        }

        // if(ntransitions_ == 0)
        //     return true;
    }
    return true;
}

State& State::operator=(const State &state) {
    n_ = state.n_;
    type_ = state.type_;
    transitions_ = state.transitions_;
    ntransitions_ = transitions_.size();
}

/**
 * @brief Sobrecarga del operador ==
 * 
 * @param state 
 * @return int 
 */
int State::operator==(const State &state) const
{
   if( this->n_ != state.n_) return 0;
   
   return 1;
}

/**
 * @brief Sobrecargar del operador <
 * 
 * @param state 
 * @return int 
 */
int State::operator<(const State &state) const
{
   if( this->n_ == state.n_) return 1;
   if( this->n_ < state.n_ ) return 1;
   return 0;
}

/**
 * @brief Sobrecarga del operador de salida
 * 
 * @param os cadena resultante
 * @param state 
 * @return ostream& 
 */
ostream& operator << (ostream& os, const State& state) {

    os << state.n_ << " " << state.type_ << " " << state.transitions_.size() << " ";

    for(auto t: state.transitions_) {
        os << t;
    }

    return os;
}
