/**
 * @file Production.hpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @date 2018-12-16
 * @version 0.1
 * @brief Fichero que contiene la clase Producción
 *
 * @copyright Copyright (c) 2018
 *
 */
#pragma once

#include <iostream>

using namespace std;

/**
 * @brief Representa una Producción de una Gramática
 *
 */
class Production {
    private:
        char state_;      // Etiqueta del estado
        char terminal_;   // símbolo terminal
        char nt_;         // símbolo no terminal;

    public:
        Production();                   // Constructor
        Production(const Production&);  // Constructor de copia

        char get_state() const;     // Obtener etiqueta del estado de la producción
        char get_terminal() const;  // Obtener símbolo terminal
        char get_nt() const;        // Obtener símbolo no terminal
        void set_state(char&);      // Establecer etiqueta del estado
        void set_terminal(char&);   // Establecer símbol terminal
        void set_nt(char&);         // Establecer símbol no terminal

    friend ostream& operator << (ostream& os, const Production& p); // salida
};