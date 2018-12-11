#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include "State.hpp"
#include "Alphabet.hpp"

using namespace std;

/**
 * @brief Representa un DFA.
 * Autómata Finito Determinista
 * 
 */
class Dfa {

  private:
    unsigned int nstates_;  // número de estados
    set<State> q_;	        // colección de estados
    unsigned int s_;		    // estado inicial
    State current_;         // estado actual
    Alphabet alphabet_;		  // alfabeto
    

  public:
    Dfa();
    Dfa(const Dfa&);
    ~Dfa();

    void clear();
    void reset();
    bool read_dfa(const string&);     // leer dfa
    const set<State>& getallstates(); // obtener todos los estados
    const set<State> get_death_states();    // obtener estados de muerte
    bool check_string(const string&); // comprobar cadena
    const Alphabet get_alphabet() const;
    


    friend ostream& operator << (ostream& os, const Dfa& dfa);

};
