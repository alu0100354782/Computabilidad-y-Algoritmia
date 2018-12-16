/**
 * @file Production.cpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @brief Métodos y funciones de la clase Production
 * @version 0.1
 * @date 2018-12-16
 *
 * @copyright Copyright (c) 2018
 *
 */
#include "../include/Production.hpp"

/**
 * @brief Construct a new Production:: Production object
 * Contructor por defecto clase Production
 *
 */
Production::Production() {}

/**
 * @brief Construct a new Production:: Production object
 * Constructor de copia
 *
 * @param p Objeto Production
 */
Production::Production(const Production& p) {
    *this = p;
}

/**
 * @brief Obtener etiqueta del estado de la producción
 *
 * @return char Etiqueta del estado de la producción
 */
char Production::get_state() const{
    return state_;
}

/**
 * @brief Obtener símbolo terminal
 *
 * @return char Símbolo terminal
 */
char Production::get_terminal() const{
    return terminal_;
}

/**
 * @brief Obtener símbolo no terminal
 *
 * @return char Símbolo no terminal
 */
char Production::get_nt() const{
    return nt_;
}

/**
 * @brief Establecer etiqueta del estado
 *
 * @param state Etiqueta del estado
 */
void Production::set_state(char& state) {
    state_ = toupper(state);
}

/**
 * @brief Establecer símbolo terminal
 *
 * @param terminal Símbolo terminal
 */
void Production::set_terminal(char& terminal) {
    terminal_ = terminal;
}

/**
 * @brief Establecer símbolo no terminal
 *
 * @param nt Símbolo no terminal
 */
void Production::set_nt(char& nt) {
    nt_ = nt;
}

/**
 * @brief Sobrecarga operador de salida
 *
 * @param os Flujo de salida
 * @param g Objeto Production
 * @return ostream& Salida formateada
 */
ostream& operator << (ostream& os, const Production& production) {
    os << production.terminal_ << production.nt_;
    return os;
}
