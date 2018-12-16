/**
 * @file Rule.cpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @brief Implementación de los métodos de la clase Rule
 * @version 0.1
 * @date 2018-12-16
 *
 * @copyright Copyright (c) 2018
 *
 */
#include "../include/Rule.hpp"

/**
 * @brief Construct a new Rule object
 * Contructor por defecto clase Rule
 *
 */
Rule::Rule() {}

/**
 * @brief Construct a new Rule:: Rule object
 * Constructor de copia
 *
 * @param rule Objeto Rule
 */
Rule::Rule(const Rule& rule) {
    *this = rule;
}

/**
 * @brief Obtener vector de producciones
 *
 * @return vector<Production> Vector de producciones
 */
vector<Production> Rule::getproductions() const {
    return productions_;
}

/**
 * @brief Insertar producción en el vector de producciones
 * @param Producción a insertar
 */
void Rule::push_back(Production& p) {
    productions_.push_back(p);
}

/**
 * @brief Sobrecarga operador de salida
 *
 * @param os Flujo de salida
 * @param g Objeto Regla
 * @return ostream& Salida formateada
 */
ostream& operator << (ostream& os, const Rule& rule) {

    for (int i=0; i<rule.productions_.size(); i++) {

        if (i>0) {

            if(rule.productions_[i-1].get_state() == rule.productions_[i].get_state()) {
                os << " | " << rule.productions_[i];
            }
            else {
                os << endl << rule.productions_[i].get_state() << " -> " << rule.productions_[i];
            }
        }
        else {
            os << rule.productions_[i].get_state() << " -> " << rule.productions_[i];
        }
    }
    os << endl;
    return os;
}
