#include "../include/Lenguaje.hpp"

Lenguaje::Lenguaje() {

}

Lenguaje::Lenguaje(const int id) {
    set_id(id);
}

Lenguaje::~Lenguaje() {

}

void Lenguaje::set_id(const int& id) {
    _id = id;
}

const int& Lenguaje::get_id() {
    return _id;
}

Lenguaje::Lenguaje(const Lenguaje& lenguaje) {
    *this = lenguaje;
}

Lenguaje::Lenguaje(std::string s) {
    definir(s);
}

const std::set<std::string>& Lenguaje::get_cadenas() {
    return _cadenas;
}

void Lenguaje::insertar_cadena(const std::string& cadena) {
    _cadenas.insert(cadena);
}

void Lenguaje::definir(std::string& lenguaje) {    
    if(lenguaje == "{}")
        _vacio = true;
    else {
        _vacio = false;
        std::string str = "";
        int i = 0;
        for(char c: lenguaje) {
            if(c != '{' && c != ',') {
                str += c;
                
                if (c == '}'){
                    str = str.substr(0, str.length() - 1);
                    _cadenas.insert(str); 
                    str = "";
                }
            }
            if (c == ',') {
                _cadenas.insert(str); 
                str = "";
            }           
        }
    }    
}

const Lenguaje Lenguaje::inversa() {
    Lenguaje resultado(_id + 1);
    std::string cadena="";

    for(std::string s: _cadenas) {
        std::reverse(s.begin(), s.end());
        resultado.insertar_cadena(s);
    }

    return resultado;
}

const Lenguaje Lenguaje::operator* (const Lenguaje& lenguaje) {
    Lenguaje resultado(lenguaje._id + 1);
    std::string cadena="";
    for(std::string cadena_L1 : _cadenas) {
        for(std::string cadena_L2 : lenguaje._cadenas) {
            if(cadena_L1 == CADENA_VACIA)
                cadena = cadena_L2;
            if(cadena_L2 == CADENA_VACIA)
                cadena = cadena_L1;
            if(cadena_L1 != CADENA_VACIA && cadena_L2 != CADENA_VACIA)
                cadena = cadena_L1 + cadena_L2;
            
            resultado.insertar_cadena(cadena);
        }
    }
    return resultado;
}

std::ostream& operator << (std::ostream& os, const Lenguaje& lenguaje) {        
    os << "L" << lenguaje._id << " = {";
    if(!lenguaje._vacio) {
        int i = 0;

        for(std::string s: lenguaje._cadenas) {            
            os << s;
            if (i < lenguaje._cadenas.size() - 1)
                os << ", ";
            i++;
        }
    }
    
    os << "}";

    return os;
}