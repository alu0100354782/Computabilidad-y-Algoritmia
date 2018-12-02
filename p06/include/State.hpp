#pragma once

#include <set>
#include "Transition.hpp"

using namespace std;

class State {

    private:
        unsigned int n_;            //número de estado
        unsigned int type_;         //1 aceptación, 0 no aceptación
        unsigned int ntransitions_; //nº de transiciones
        set<Transition> transitions_; //transiciones 

    public:
        State();
        State(const State&);
        ~State();

        const unsigned int& getn();
        const unsigned int& gettype() ;
        const unsigned int& getntransitions();
        const set<Transition>& gettransitions();

        void setn(unsigned int&);
        void settype(unsigned int&);
        void setntransitions(unsigned int&);
        void inserttransitions(Transition&);

        bool deadstate();//estado de muerte o no

        State& operator=(const State &);
		int operator==(const State &) const;
		int operator<(const State &) const;

    //sobrecarga de la salida
    friend ostream& operator << (ostream&, const State&);
};
