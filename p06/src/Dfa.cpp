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
    string line;
    ifstream file(path);

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
                    istringstream iss(line);
                    string token;
                    unsigned int ntoken = 0;
                    set<Transition> transitions;

                    unsigned int tfull = 0;
                    State s;

                    while(iss >> token) {//recorrer línea

                        Transition t;
                        unsigned int n;
                        char symbol; unsigned int toState;
                        ntoken++;
                        switch(ntoken) {
                            case 1: //número de estado
                                unsigned int n;
                                istringstream(token) >> n;
                                s.setn(n);
                                break;
                            case 2: //estado de aceptación o no
                                unsigned int aceptation;
                                istringstream(token) >> aceptation;
                                s.settype(aceptation);
                                break;
                            case 3: //cantidad de transiciones
                                unsigned int ntransitions;
                                istringstream(token) >> ntransitions;
                                s.setntransitions(ntransitions);
                                break;
                            default://transiciones
                                if(ntoken%2 == 0) {//simbolo
                                  // tfull++;
                                  istringstream(token) >> symbol;
                                  alphabet_.insert(symbol);
                                }
                                else {//estado
                                  // tfull++;
                                  istringstream(token) >> toState;
                                }
                                tfull++;
                                break;

                        }//end switch(ntoken)
                        // cout << "Tamaño alfabeto " << alphabet_.size() << endl;
                        if (tfull == sizealphabet_) {//transicion completa
                        // if (tfull == alphabet_.size()) {//transicion completa
                            t = Transition(symbol,toState);
                            s.inserttransitions(t);
                            tfull = 0;
                        }




                    }//end while

                    this->q_.insert(s);
                    break;
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
const set<State> Dfa::get_death_states() const {

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
 * @return const set<char> 
 */
const set<char> Dfa::get_alphabet() const {
  return this->alphabet_;
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
                            if (q.getn() == t.gettoState())
                                next_state = q;
                        }


                        cout << q.getn() << "\t\t" << t.getsymbol();

                        cout << "\t\t" << t.gettoState() << endl;

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
    os << endl << endl;
    return os;
}
