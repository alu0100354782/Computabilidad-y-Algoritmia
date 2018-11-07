#pragma once
#include <iostream>

class Bloque {

    private:
        int _ancho;
        int _alto = 1;

    public:
        Bloque();
        Bloque(const Bloque& bloque);
        Bloque(const int& ancho);
        ~Bloque();
        
        const int& getAncho();

        bool operator==(const Bloque &bloque);

    friend std::ostream& operator<< (std::ostream& os, Bloque &bloque);
};
