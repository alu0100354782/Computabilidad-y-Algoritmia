/**
 * @file State.hpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @date 2018-12-16
 * @version 0.1
 * @brief Fichero que contiene la clase Estado
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once

#include <set>
#include "Transition.hpp"

using namespace std;

class State {

    private:
        unsigned int id_;               //número de estado
        unsigned int type_;             //1 aceptación, 0 no aceptación
        unsigned int ntransitions_;     //nº de transiciones
        set<Transition> transitions_;   //transiciones

    public:
        State();            // constructor por defecto
        State(const State&);// construtor de copia
        ~State();           // destructor

        const unsigned int& getid();            // obtener id del estado
        const unsigned int& gettype() ;         // obtener tipo de estado (1 aceptación, 0 no aceptación)
        const unsigned int& getntransitions();  // obtener nº de transiciones
        const set<Transition>& gettransitions();// obtener conjunto de transiciones
        const unsigned int& next(const char&);  // obtener id del estado al transitar con un símbolo dado

        void setid(unsigned int&);              // establecer id del estado
        void settype(unsigned int&);            // establecer tipo de estado
        void setntransitions(unsigned int&);    // establecer nº de transiciones
        void inserttransitions(Transition&);    // insertar transiciones
        bool deadstate();                       // estado de muerte o no

		int operator==(const State &rhs) const; // sobrecarga operador igualdad
		int operator<(const State &rhs) const;  // sobrecarga operador menor que

        friend ostream& operator << (ostream&, const State&); // salida
};
