/**
 * @file Alphabet.hpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es) 
 * @brief  Fichero que contiene la clase Alfabeto
 * @version 0.1
 * @date 2018-12-16
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once

#include <iostream>
#include <set>

using namespace std;

/**
 * @brief Alfabeto de un Lenguaje
 * 
 */
class Alphabet {

    private:
        set<char> _symbols;  //conjunto de símbolos

    public:
        Alphabet();                     // constructor por defecto
        Alphabet(const Alphabet &);     // constructor de copia
        ~Alphabet();                    // destructor

        // getters y setters
        const set<char>& getsymbols();
        void setsymbols(const set<char>&);

        void insert(const char&);   // insertar símbolo
        void clear();               // vaciar alfabeto
        int size() const;           // tamañano del alfabeto

    // sobrecarga del operador de salida
    friend ostream& operator << (ostream &, const Alphabet &);
};
