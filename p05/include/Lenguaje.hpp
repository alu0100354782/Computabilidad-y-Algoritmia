#pragma once

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include "Alfabeto.hpp"

#define CADENA_VACIA "&"

class Lenguaje {

    private:
        int _id;
        Alfabeto _alfabeto;
        std::set<std::string> _cadenas;
        bool _vacio;

    public:
        Lenguaje();
        Lenguaje(const int id);
        Lenguaje(const Lenguaje&);
        Lenguaje(std::string);
        virtual ~Lenguaje();
        void set_id(const int& id);
        const int& get_id();
        const std::set<std::string>& get_cadenas();
        void insertar_cadena(const std::string&);
        void definir(std::string&);
        const Lenguaje inversa();
        const Lenguaje operator* (const Lenguaje&);
        

    friend std::ostream& operator << (std::ostream&, const Lenguaje&);
};