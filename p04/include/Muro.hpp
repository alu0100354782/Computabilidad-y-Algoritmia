#pragma once

#include <vector>
#include "Fila.hpp"

class Muro {

    private:
        std::vector<Fila> _filas;
        int _ancho;
        int _alto;        

        std::vector<Fila> _fposibles;   // combinaciones de filas posibles        
        

    public:
        Muro(const int &ancho, const int &alto);
        Muro(const Muro &muro);
        ~Muro();

        void setDimension(const int &ancho, const int &alto);
        void setFila(const Fila &fila);
        const Fila& getFila(const int &i);

        void generarFilas(Fila& fila, int &ancho_actual);

        void comprobar();

    friend std::ostream& operator<< (std::ostream& os, Muro &muro);
};