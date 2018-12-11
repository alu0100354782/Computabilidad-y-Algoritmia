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
