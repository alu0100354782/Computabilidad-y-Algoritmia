#pragma once

#include <vector>
#include "Bloque.hpp"


class Fila {
    
    private:        
        std::vector<Bloque> _bloques;        

    public:
        Fila();
        ~Fila();

        void ponerBloque(const int &sFila, const Bloque &b);

        const std::vector<Bloque>& getBloques();

    friend std::ostream& operator<< (std::ostream& os, Fila &fila);
};