/**
 * @file Grammar.cpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @brief Funciones y métodos de la clase Grammar
 * @version 0.1
 * @date 2018-12-16
 *
 * @copyright Copyright (c) 2018
 *
 */
#include "../include/Grammar.hpp"

/**
 * @brief Construct a new Grammar object
 * Contructor por defecto clase State
 *
 */
Grammar::Grammar() {}

/**
 * @brief Construct a new Grammar:: Grammar object
 * Constructor de copia
 *
 * @param grammar
 */
Grammar::Grammar(const Grammar& grammar) {
    *this = grammar;
}

/**
 * @brief Construct a new Grammar object
 * Contructor para crear Gramática a partir de un DFA
 * @param dfa Objeto DFA
 *
 */
Grammar::Grammar(Dfa& dfa) {
    define_productions(dfa);
}

/**
* @brief Definir reglas y producciones a partir de un DFA
* @param dfa Objeto DFA
*
*/
void Grammar::define_productions(Dfa& dfa) {
    int i=0;
    Rule rule;
    for(auto q: dfa.getallstates()) {
        Production production;
        production.set_state(labels_[i]);
        nt_.insert(labels_[i]);

        for(auto t: q.gettransitions()) {//una transción = una producción
            char t_symbol = t.getsymbol();
            production.set_terminal(t_symbol);
            production.set_nt(labels_[t.gettostate()]);
            alphabet_.insert(t_symbol);

            rule.push_back(production);
        }

        if(q.gettype() == 1) {
            Production e_prod;
            e_prod.set_state(labels_[i]);
            char epsilon = '~';
            char nt_epsilon = ' ';
            e_prod.set_terminal(epsilon);
            e_prod.set_nt(nt_epsilon);
            rule.push_back(e_prod);
        }

        i++;
    }
    productions_.push_back(rule);
}

/**
 * @brief Exportar DFA a fichero
 * @param Nombre fichero
 */
void Grammar::to_file(string filename) {

    ofstream file;
    file.open(filename, ios::trunc);
    string line = "";

    //linea 1 nº de símbolos no terminales
    file << alphabet_.size() << endl;

    //linea 2 símbolos del alfabeto
    for(auto s: alphabet_.getsymbols()) {
        file << s << " ";
    }
    file << endl;

    // linea 3 nº total de símbolos no terminales
    file << nt_.size() << endl;

    //linea 4 lista de todos los símbolos no terminales
    for(auto s: nt_) {
        file << s << " ";
    }
    file << endl;

    //lineas de producciones
    for(int i=0; i<productions_.size(); i++) {
        //if(i<productions_.size() - 1) {
            file << productions_[i];
        //}
    }

    file.close();
}

/**
 * @brief Sobrecarga operador de salida
 *
 * @param os Flujo de salida
 * @param g Objeto Gramática
 * @return ostream& Salida formateada
 */
ostream& operator << (ostream& os, const Grammar& g) {
    //linea 1 nº de símbolos no terminales
    os << g.alphabet_.size() << endl;
    
    //linea 2 símbolos del alfabeto
    os << g.alphabet_ << endl;
    
    // linea 3 nº total de símbolos no terminales
    os << g.nt_.size() << endl;
    
    //linea 4 lista de todos los símbolos no terminales
    for(auto nt: g.nt_) {
        os << nt << " ";
    }
    os << endl;

    //lineas de producciones
    for(int i=0; i<g.productions_.size(); i++) {
        os << g.productions_[i] << endl;
    }

    return os;
}
