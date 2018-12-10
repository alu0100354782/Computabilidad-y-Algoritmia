#include "../include/Nfa.hpp"

/**
 *
 * @brief Construct a new Nfa:: Nfa object
 * Constructor por defecto
 *
 */
Nfa::Nfa() {}

/**
 * @brief Construct a new Nfa:: Nfa object
 * Contructor de copia
 *
 * @param nfa
 */
Nfa::Nfa(const Nfa& nfa) {
    *this = nfa;
}

/**
 * @brief Destroy the Nfa:: Nfa object
 * Destructor
 *
 */
Nfa::~Nfa() {
    clear();
}

/**
 * @brief Limpiar NFA
 *
 */
void Nfa::clear() {
  q_.clear();
  nstates_ = 0;
  s_ = 0;
  alphabet_.clear();
}



/**
 * @brief Leer NFA del fichero
 *
 * @param path ruta del fichero
 * @return true fichero leído con éxito
 * @return false error al leer el fichero
 */
bool Nfa::read_nfa(const string& path) {
    string line = "";
    ifstream file(path);
    unsigned int n;

    if(file.is_open()) {
        unsigned int nline = 0;

        while(getline(file, line)) {
            nline++;

            switch(nline) {
                case 1: //línea 1 número de estados
                    istringstream(line) >> this->nstates_;
                    break;
                case 2://línea 2 estado inicial
                    istringstream(line) >> this->s_;
                    break;
                default://línea 3 en adelante, transiciones
                    if(nline < nstates_ + 3) {
                        istringstream iss(line);
                        string token;
                        unsigned int ntoken = 0;
                        set<Transition> transitions;
                        State s;
                        unsigned int ntransitions;

                        while(iss >> token) {//recorrer línea

                            Transition t;
                            unsigned int n;
                            char symbol; unsigned int toState;
                            ntoken++;
                            switch(ntoken) {
                                case 1: //número de estado
                                    istringstream(token) >> n;
                                    s.setid(n);
                                    break;
                                case 2: //estado de aceptación o no
                                    unsigned int type;
                                    istringstream(token) >> type;
                                    s.settype(type);
                                    break;
                                case 3: //cantidad de transiciones
                                    istringstream(token) >> ntransitions;
                                    s.setntransitions(ntransitions);
                                    break;
                                default://transiciones
                                    if(ntransitions < (ntransitions*2)) {

                                        if(ntoken%2 == 0) {//simbolo
                                            istringstream(token) >> symbol;
                                            if(symbol != '~')
                                                alphabet_.insert(symbol);
                                        }
                                        else {//estado
                                            istringstream(token) >> toState;
                                            t = Transition(symbol,toState);
                                            s.inserttransitions(t);
                                        }
                                    }
                                    else {
                                        cout << "Error: fichero mal construído."
                                             << "Nº de transiciones incorrecto para el estado: "
                                             << s.getid() << endl;
                                        return false;
                                    }

                                    break;

                            }//end switch(ntoken)
                        }//end while

                        this->q_.insert(s);
                        break;
                    }//end if(nline < nstates_ - 3)
                    else {
                        cout << "Error: fichero mal construído. Nº de estados incorrecto" << endl
                            << "El fichero indica " << nstates_ << " pero tiene " << nline-2 << endl;
                        return false;
                    }
            }//end switch(nlines)*/
        }//while(getline(file, line))

    }//end if(file.is_open())

    else {
        cout << "Error: no se puede leer el fichero" << endl;
        return false;
    }

    return true;
}

/**
 * @brief Obtener el conjunto de estados
 *
 * @return const set<State>& conjunto de estados
 */
const set<State>& Nfa::getallstates() {
    return this->q_;
}

/**
 * @brief Obtener conjunto de estados de muerte
 *
 * @return const set<State> conjunto de estados de muerte
 */
const set<State> Nfa::get_death_states() const {

    set<State> ds;

    for(auto x: this->q_) {

        if (x.deadstate())
            ds.insert(x);
    }

    return ds;
}

/**
 * @brief Obtener el conjunto de estados importantes del NFA.
 * Estados con transiciones que no son epsilon-transiciones
 *
 * @return const set<State> conjunto de estados importantes
 */
const set<State> Nfa::get_important_states() const {
    set<State> is;

    for(auto x: this->q_) {

        if (x.important())
            is.insert(x);
    }

    return is;
}

/**
 * @brief Obtener el alfabeto del NFA
 *
 * @return Alphabet alfabeto del NFA
 */
const Alphabet Nfa::get_alphabet() const {
  return alphabet_;
}

/*Implementar función transitar para usar recursivamente

    transitar(string cadena, int indice, State estado_actual)
*/

/**
 * @brief Comprobar si el NFA reconoce la cadena
 *
 * @param str cadena
 * @return true reconoce la cadena
 * @return false no reconoce la cadena
 */
bool Nfa::check_string(const string& str) {
    int i=0;
    istringstream iss(str);
    char token;
    State next_state = *q_.begin();

    cout << "Estado actual\tEntrada\t\tSiguiente estado" << endl;

    while(iss >> token) { //recorrer cadena

        current_ = next_state;//estado actual

        for(State q: epsilon_closure()) { //recorrer estados            

            for(Transition t: q.gettransitions()) { //recorrer transiciones

                if(token == t.getsymbol()) {

                    for(State q2: q_) { //recorrer estados para obtener estado siguiente
                        if (q2.getid() == t.gettoState())
                            next_state = q2;
                    }

                    cout << q.getid() << "\t\t" << t.getsymbol();
                    cout << "\t\t" << t.gettoState() << endl;

                }
            }

            token = iss.peek();

            if (token = EOF) {
                break;
            }
           i++; 
        }
    }

    cout << endl;
    current_ = next_state;
    
    if (i == str.length() && current_.gettype() == 1){    
        cout << "Cadena de entrada ACEPTADA" << endl;
        return true;
    }
    else {
        cout << "Cadena de entrada NO ACEPTADA" << endl;
        return false;
    }
}

/**
 * @brief Comprueba si el NFA cargado es también un DFA
 *
 * @return true es DFA
 * @return false no es DFA
 */
bool Nfa::is_dfa() const {
    // return (q_.size() * alphabet_.size() == );
    for(State s: q_) {
        if (s.getntransitions() != alphabet_.size())
            return false;
    }

    return true;
}

/**
 * @brief Obtener conjunto de estados que se alcanzan con 
 * epsilon transiciones desde estado actual
 * 
 * @return const set<State> Conjunto de estados
 */
const set<State> Nfa::epsilon_closure() {
    set<State> e_closure;
    for (Transition t: current_.gettransitions()) {        
        if(t.is_epsilon()) {
            for (State s: q_) {
                if(s.getid() == t.gettoState())
                    e_closure.insert(s);    
            }            
        }            
    }
    for(State s: e_closure){
        std::cout << s << std::endl;
    }
    
    return e_closure;
}

/**
 * @brief Sobrecarga del operador de salida
 *
 * @param os flujo de salida
 * @param nfa objeto a mostrar
 * @return ostream& salida formateada
 */
ostream& operator << (ostream& os, const Nfa& nfa) {

    os << nfa.nstates_ << endl;
    os << nfa.s_ << endl;

    for(auto q: nfa.q_) {
        os << q << endl;

    }

    return os;
}
