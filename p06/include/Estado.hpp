#pragma once

#include <set>
#include "Transicion.hpp"

class Transicion;

/**
 * @brief Representa un estado del DFA
 * 
 */
class Estado {

    private:
        unsigned int _id;                   // id de estado
        unsigned int _tipo;                 // 1 aceptación, 0 no aceptación
        std::set<Transicion> _transiciones; // conjunto de transiciones

    public:
        // Constructores
        Estado();
        Estado(const Estado&);
        
        // Destructor
        virtual ~Estado();

        // Getters y Setters
        const unsigned int& get_id();
        void set_id(const unsigned int&);

        const unsigned int& get_tipo();
        void set_tipo(const unsigned int&);

        const std::set<Transicion>& get_transiciones();
        void set_transiciones(const std::set<Transicion>&);

        
        void insertar_transicion(Transicion&);

        const bool es_estado_de_muerte();

        // Sobrecarga de operadores
        int operator == (const Estado&) const;
        int operator != (const Estado&) const;
        int operator < (const Estado&) const;

    // Sobrecarga del operador de salida
    friend std::ostream& operator << (std::ostream&, const Estado&);
};