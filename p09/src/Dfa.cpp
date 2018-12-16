/**
 * @file Dfa.cpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @brief Funciones y métodos de la clase Dfa
 * @version 0.1
 * @date 2018-12-16
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "../include/Dfa.hpp"

/**
 * 
 * @brief Construct a new Dfa:: Dfa object
 * Constructor por defecto
 * 
 */
Dfa::Dfa() {}

/**
 * @brief Destroy the Dfa:: Dfa object
 * Destructor
 * 
 */
Dfa::~Dfa() {
    q_.clear();
}

/**
 * @brief Obtener el estado inicial del DFA
 * 
 * @return const unsigned int& estado inicial
 */
const unsigned int& Dfa::get_s() {
    return s_;
}

/**
 * @brief Limpiar DFA
 * 
 */
void Dfa::clear() {
  q_.clear();
  nstates_ = 0;
  s_ = 0;
  alphabet_.clear();
}



/**
 * @brief Leer DFA del fichero
 * 
 * @param path ruta del fichero
 * @return true 
 * @return false 
 */
bool Dfa::read_dfa(const string& path) {
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
 * @brief Guardar DFA en nuevo fichero
 * 
 * @param filename nombre de fichero
 */
void Dfa::save_dfa(const string& filename) {
    
    ofstream file(filename); 

    file << q_.size() << endl;
    file << s_ << endl;
   
    for(State state: q_) {
        file << state.getid() << " " << state.gettype() << " " << state.gettransitions().size();

        for(Transition t: state.gettransitions()) {
            file << " " << t.getsymbol() << " " << t.gettostate();
        }
        file << endl;
    }
   file.close();
}

/**
 * @brief Obtener el conjunto de estados
 * 
 * @return const set<State>& 
 */
const set<State>& Dfa::getallstates() {
    return this->q_;
}

/**
 * @brief Obtener conjunto de estados de muerte
 * 
 * @return const set<State> 
 */
const set<State> Dfa::get_death_states(){

    set<State> ds;

    for(auto x: this->q_) {

        if (x.deadstate())
            ds.insert(x);
    }

    return ds;
}

/**
 * @brief Getter del alfabeto del DFA
 * 
 * @return const Alphabet alfabeto
 */
const Alphabet Dfa::get_alphabet() const {
  return alphabet_;
}

/**
 * @brief Comprobar si el DFA genera la cadena
 * 
 * @param str cadena
 * @return true 
 * @return false 
 */
bool Dfa::check_string(const string& str) {

    int i=0;
    istringstream iss(str);
    char token;
    State next_state = *q_.begin();

    cout << "Estado actual\tEntrada\t\tSiguiente estado" << endl;

    while(iss >> token) { //recorrer cadena

        current_ = next_state;//estado actual

        for(auto q: q_) { //recorrer estados

            if (q == current_) {

                for(auto t: q.gettransitions()) { //recorrer transiciones

                    if(token == t.getsymbol()) {

                        for(auto q: q_) { //recorrer estados para obtener estado siguiente
                            if (q.getid() == t.gettostate())
                                next_state = q;
                        }


                        cout << q.getid() << "\t\t" << t.getsymbol();

                        cout << "\t\t" << t.gettostate() << endl;

                        i++;

                        //break;
                    }
                }

                token = iss.peek();

                if (token = EOF) {
                    break;
                }
            }
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
 * @brief Minimizar DFA
 * 
 */
void Dfa::minimize() {
    set<set<State>> Pi;
    set<set<State>> PiB;
    set<State> aceptation_states;
    set<State> normal_states;

    int n_states = 1;

    for(State state: q_) {
        if(state.gettype() == 1) {
            aceptation_states.insert(state);
        }
        else
            normal_states.insert(state);
    }

    Pi.insert(aceptation_states);
    Pi.insert(normal_states);

    cout << "P0:{";
    for(set<State> set_states: Pi) {
        cout << "{";
        for (State s: set_states) {
            cout << s.getid() << ", ";
        }
        cout << "} ";
    }
    cout << "}" << endl;

    while(Pi != PiB) {
        PiB = Pi;
        Pi = new_partition(PiB, n_states);
    }

    n_states = 0;

    for(set<State> set_states: Pi) 
        n_states++;
    
    cout << endl << "Nº de estados DFA mínimo: " << n_states << endl;
}

/**
 * @brief Crea una nueva partición de estados
 * 
 * @param Pi 
 * @param n_states 
 * @return const set<set<State>> 
 */
const set<set<State>> Dfa::new_partition(set<set<State>>& Pi, int& n_states){
    set<set<State>> set_set_states; 
    set<set<State>> PiNew ;    
    
    for(set<State> states: Pi) {
        set_set_states = factorize(states,Pi,n_states);
        PiNew.insert(set_set_states.begin(), set_set_states.end());
    }    
    
    return PiNew;
}

/**
 * @brief Junta los estados equivalentes
 * 
 * @param states 
 * @param Pi 
 * @param n_states 
 * @return const set<set<State>> 
 */
const set<set<State>> Dfa::factorize(set<State>& states, set<set<State>>& Pi, int& n_states) {
    set<set<State>> set_set_states;
    set_set_states.insert(states);
    
    for(char symbol: alphabet_.getsymbols()) {
        set<set<State>> aux;

        for(set<State> ss: set_set_states) {
            aux = split(ss, symbol, Pi);            
        }
        set_set_states = aux;
        print_set_states(set_set_states, n_states, symbol, states, Pi);
    }
    return set_set_states;
}

/**
 * @brief Separa estados no equivalentes
 * 
 * @param G 
 * @param symbol 
 * @param Pi 
 * @return const set<set<State>> 
 */
const set<set<State>> Dfa::split(set<State>& G, char& symbol, set<set<State>>& Pi) {
    set<set<State>> T;
    for(set<State> H: Pi) {
        set<State> state;

        for(State sG: G) {
            
            for(State sH: H) {
                
                if(sG.next(symbol) == sH.getid())
                    state.insert(sG);
            }
        }
        if(!state.empty())
            T.insert(state);
    }

    return T;
}

/**
 * @brief Muestra los conjuntos de estados del algoritmo minimización de estados
 * 
 * @param partition 
 * @param n_states 
 * @param symbol 
 * @param G 
 * @param Pi 
 */
void Dfa::print_set_states(set<set<State>>& partition, int& n_states, char& symbol, set<State>& G, set<set<State>>& Pi) {
    cout << "Con el símbolo '" << symbol << "':" << endl;
    cout << "P"<< n_states << ":{";

    for(set<State> ss: partition) {
        cout << "{";
        for(State s: ss) {
            cout<< s.getid() << ",";
        }
        cout << "} ";
    }

    for(set<State> ss: Pi) {
        if(ss != G) {
            cout << "{";
            for(State s: ss) {
                cout << s.getid() << ",";
            }
            cout << "}";
        }
    }
    cout << "}" << endl;
}

ostream& operator << (ostream& os, const Dfa& dfa) {

    os << dfa.nstates_ << endl;
    os << dfa.s_ << endl;

    for(auto q: dfa.q_) {
        os << q << endl;
    }
    
    return os;
}
