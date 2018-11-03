#pragma once

#include <vector>
#include "Fila.hpp"

class Muro {

    private:
        std::vector<Fila> _filas;
        int _largo;
        int _ancho;

    public:
        Muro();
        ~Muro();

        void setDimension(const int &largo, const int &ancho);
        void setFila(const Fila &fila);
        const Fila& getFila(const int &i);

    friend std::ostream& operator<< (std::ostream& os, Muro &muro);
};