/**
 * @file Transition.hpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @brief Fichero que contiene la clase Transición
 * @version 0.1
 * @date 2018-12-16
 *
 * @copyright Copyright (c) 2018
 *
 */
#pragma once

#include <iostream>


using namespace std;

class Transition {

    private:
        char symbol_;           //símbolo entrante
        unsigned int tostate_;  //estado al que se transita

    public:
        Transition();                   // Constructor por defecto
        Transition(char, unsigned int); // Constructor por parámetros
        Transition(const Transition& t);// Constructor de copia

        const char& getsymbol();            // Obtener símbolo
        const unsigned int& gettostate();   // Obtener estado al que se transita

        void setsymbol(char&);  // Establecer símbolo
        void settostate(int&);  // Establecer estado al que se transita

        Transition& operator=(const Transition &rhs);   // Sobrecarga del operador de asignación
		int operator==(const Transition &rhs) const;    // Sobrecarga del operador de igualdad
		int operator<(const Transition &rhs) const;     // Sobrecarga del operador de menor que

        friend ostream& operator << (ostream&, const Transition&);  // Sobrecarga del operador de salida
};
