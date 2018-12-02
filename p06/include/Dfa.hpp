#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include "State.hpp"


using namespace std;

class Dfa {

  private:
    unsigned int nstates_;//número de estados
    set<State> q_;	      //colección de estados
    unsigned int s_;		  //estado inicial
    State current_;       //estado actual
    unsigned int sizealphabet_ = 2;
    set<char> alphabet_;

  public:
    Dfa();
    ~Dfa();

    void clear();    
    bool read_dfa(const string&);         //leer dfa
    const set<State>& getallstates();    //obtener todos los estados
    const set<State> get_death_states() const; //obtener estados de muerte
    bool check_string(const string&);     //comprobar cadena

    const set<char> get_alphabet() const;


    friend ostream& operator << (ostream& os, const Dfa& dfa);

};
