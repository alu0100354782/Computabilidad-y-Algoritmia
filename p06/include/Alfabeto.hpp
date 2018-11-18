#pragma once

#include <set>

class Alfabeto {
    
    private:
        std::set<char> _simbolos;

    public:
        Alfabeto();
        Alfabeto(const Alfabeto &);
        virtual ~Alfabeto();
        const std::set<char>& getSimbolos();
        void setSimbolos(const std::set<char> &);
        void insertar(const char &);
        const int size();
};