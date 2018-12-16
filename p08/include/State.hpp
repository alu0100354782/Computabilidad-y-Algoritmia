#pragma once

#include <set>
#include "Transition.hpp"

using namespace std;

class State {

    private:
        unsigned int id_;            //número de estado
        unsigned int type_;         //1 aceptación, 0 no aceptación
        unsigned int ntransitions_; //nº de transiciones
        set<Transition> transitions_; //transiciones

    public:
        State();
        State(const State&);
        ~State();

        const unsigned int& getid();
        const unsigned int& gettype() ;
        const unsigned int& getntransitions();
        const set<Transition>& gettransitions();
        const unsigned int& next(const char&);

        void setid(unsigned int&);
        void settype(unsigned int&);
        void setntransitions(unsigned int&);
        void inserttransitions(Transition&);
        bool deadstate();//estado de muerte o no
                        
		int operator==(const State &rhs) const;
		int operator<(const State &rhs) const;

        //sobrecarga de la salida
        friend ostream& operator << (ostream&, const State&);
};
