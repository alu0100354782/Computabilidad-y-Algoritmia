#pragma once

#include <iostream>
#include "Estado.hpp"

class Estado;

/**
 * @brief Representa una transición del DFA
 * 
 */
class Transicion {

    private:
        char _simbolo;          // símbolo entrante
        Estado* _hacia_estado;   // estado al que se transita

    public:
        // Constructores
        Transicion();
        Transicion(const char&, Estado*);
        Transicion(const Transicion&);
        
        // Destructor
        virtual ~Transicion();

        // Getters y Setters
        const char& get_simbolo();
        void set_simbolo(const char&);

        Estado* get_hacia_estado();
        void set_hacia_estado(Estado*);

        // Sobrecarga de operadores
        Transicion& operator = (const Transicion&);
        int operator == (const Transicion&) const;
        int operator < (const Transicion&) const;

    // Sobrecarga del operador de salida
    friend std::ostream& operator << (std::ostream&, const Transicion&);
};