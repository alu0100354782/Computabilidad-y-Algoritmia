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
            //cout << x.getn() << " ";

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

ostream& operator << (ostream& os, const Dfa& dfa) {

    os << dfa.nstates_ << endl;
    os << dfa.s_ << endl;

    for(auto q: dfa.q_) {
        os << q << endl;
    }
    
    return os;
}
