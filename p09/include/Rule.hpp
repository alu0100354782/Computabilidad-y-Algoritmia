/**
 * @file Rule.hpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @date 2018-12-16
 * @version 0.1
 * @brief Fichero que contiene la clase Regla
 *
 * @copyright Copyright (c) 2018
 *
 */
#pragma once

#include <vector>
#include "Production.hpp"

/**
 * @brief Representa una Regla de una Gramática
 *
 */
class Rule {

    private:
        vector<Production> productions_; // vector de produciones

    public:
        Rule();             // Constructor
        Rule(const Rule&);  // Constructor de copia

        vector<Production> getproductions() const;  // obtener producciones
        void push_back(Production&);                // insertar producción

    friend ostream& operator << (ostream& os, const Rule& rule); // operador de salida
};