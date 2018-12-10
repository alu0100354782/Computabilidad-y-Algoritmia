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
 * @param state estado a copiar
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
 * @return const unsigned& State::getid identificador del estado
 */
const unsigned int& State::getid() {
    return this->id_;
}

/**
 * @brief Obtener tipo de estado,
 * si es 1 es de aceptación
 *
 * @return const unsigned& State::gettype tipo de estado: 1 aceptación, 0 No aceptación
 */
const unsigned int& State::gettype()  {
    return this->type_;
}

/**
 * @brief Obtener nº de transiciones del estado
 *
 * @return const unsigned& State::getntransitions nº de transiciones
 */
const unsigned int& State::getntransitions() {
    return this->ntransitions_;
}

/**
 * @brief Obtener el conjunto de transiciones del estado
 *
 * @return const set<Transition>& conjunto de transiciones
 */
const set<Transition>& State::gettransitions() {
    return this->transitions_;
}

/**
 * @brief Establecer identificador del estado
 *
 * @param id número identificador del estado
 */
void State::setid(unsigned int &id) {
    this->id_ = id;
}

/**
 * @brief Establecer tipo de estado
 *
 * @param type 1 aceptación, 0 no aceptación
 */
void State::settype(unsigned int &type) {
    this->type_ = type;
}

/**
 * @brief Establecer nº de transiciones
 *
 * @param ntransitions nº de transiciones
 */
void State::setntransitions(unsigned int &ntransitions) {
    this->ntransitions_ = ntransitions;
}

/**
 * @brief Insertar transición
 *
 * @param t transición
 */
void State::inserttransitions(Transition &t) {
    this->transitions_.insert(t);
}

/**
 * @brief Comprobar si es un estado de muerte
 *
 * @return true es estado de muerte
 * @return false no es estado de muerte
 */
bool State::deadstate() {
    if (type_ == 1)
        return false;

    if (transitions_.size() == 0)
      return true;

    for(int i = 0; i < this->transitions_.size(); i++) {

        set<Transition>::iterator it = transitions_.begin();
        advance(it, i);
        Transition x = *it;

        if(x.gettoState() != id_) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Comprobar si el estado es importante.
 * Un estado no es importante si sus únicas transiciones
 * son epsilon-transiciones
 *
 * @return true es importante
 * @return false no es importante
 */
bool State::important() {
    int i = 0;
    for(Transition t: transitions_) {
        if (t.getsymbol() == '~')
            i++;
    }

    if (ntransitions_ == i)
        return false;

    return true;
}

/**
 * @brief Sobrecarga del operador =
 *
 * @param state estado que se asigna al actual
 * @return State& estado resultante
 */
State& State::operator=(const State &state) {
    id_ = state.id_;
    type_ = state.type_;
    transitions_ = state.transitions_;
    ntransitions_ = transitions_.size();
}

/**
 * @brief Sobrecarga del operador ==
 *
 * @param state estado que se compara con el actual
 * @return int 0 si es distinto, 1 si es igual
 */
int State::operator==(const State &state) const
{
   if( this->id_ != state.id_) return 0;

   return 1;
}

/**
 * @brief Sobrecargar del operador <
 *
 * @param state estado que se compara con el actual
 * @return int 0 si es mayor, 1 si es menor o igual
 */
int State::operator<(const State &state) const
{
   if( this->id_ == state.id_) return 1;
   if( this->id_ < state.id_ ) return 1;
   return 0;
}

/**
 * @brief Sobrecarga del operador de salida
 *
 * @param os cadena resultante
 * @param state estado a mostrar
 * @return ostream& flujo de salida
 */
ostream& operator << (ostream &os, const State &state) {

    os << state.id_ << " " << state.type_ << " " << state.transitions_.size() << " ";

    for(auto t: state.transitions_) {
        os << t;
    }

    return os;
}
