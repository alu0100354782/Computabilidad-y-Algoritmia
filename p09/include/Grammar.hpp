/**
 * @file Grammar.hpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @date 2018-12-16
 * @version 0.1
 * @brief Fichero que contiene la clase Gramática
 *
 * @copyright Copyright (c) 2018
 *
 */
#pragma once

#include "Rule.hpp"
#include "Dfa.hpp"
#include "Alphabet.hpp"

using namespace std;

/**
 * @brief Representa una Gramática Regular
 *
 */
class Grammar {

    private:
        set<char> nt_;              // conjunto de símbolos no terminales
        vector<Rule> productions_;  // reglas de sustitución (producciones)
        Alphabet alphabet_;         // alfabeto

        vector<char> labels_ = {'S','A','B','C',
                                'D','E','F','G',
                                'H','I','J','K',
                                'L','M','N','O'}; // etiquetas de estados

    public:
        Grammar();              // Constructor por defecto
        Grammar(const Grammar&);// Constructor de copia
        Grammar(Dfa&);          // Constructor a partir de DFA

        void define_productions(Dfa&);  // definir producciones
        void to_file(string);           // guardar en fichero

    friend ostream& operator << (ostream& os, const Grammar& g); // salida
};