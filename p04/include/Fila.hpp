#pragma once

#include <vector>
#include "Bloque.hpp"


class Fila {
    
    private:        
        std::vector<Bloque> _bloques;
        int _longitud;
        int _nFila;


    public:
        Fila();
        Fila(const Fila &fila);
        ~Fila();

        const int& getLongitud();

        void ponerBloque(const int &nFila, Bloque &b);

        const std::vector<Bloque>& getBloques();

        bool operator==(const Fila &fila);

    friend std::ostream& operator<< (std::ostream& os, Fila &fila);
};