#pragma once

#include <vector>
#include "Transition.hpp"

using namespace std;

/**
 * @brief Representa un estado de un NFA
 * 
 */
class State {

    private:
        unsigned int id_;               // id de estado
        unsigned int type_;             // 1 aceptación, 0 no aceptación
        unsigned int ntransitions_;     // nº de transiciones
        vector<Transition> transitions_;   // transiciones

    public:
        State();                // constructor por defecto
        State(const State&);    // constructor de copia
        ~State();               // destructor

        // getters y setters
        const unsigned int& getid();
        const unsigned int& gettype() ;
        const unsigned int& getntransitions();

        const vector<Transition>& gettransitions();
        void setid(unsigned int &);
        void settype(unsigned int &);
        void setntransitions(unsigned int &);

        void inserttransitions(Transition&);    // insertar transición
        bool deadstate();                       // es estado de muerte
        bool important();                       // es estado importante

        State& operator=(const State &);        // sobrecarga del operador =
		int operator==(const State &) const;    // sobrecarga del operador ==
		int operator<(const State &) const;     // sobrecarga del operador <

    // sobrecarga del operador de salida
    friend ostream& operator << (ostream&, const State&);
};
