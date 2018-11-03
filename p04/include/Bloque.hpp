#pragma once
#include <iostream>

class Bloque {

    private:
        int _size;

    public:
        Bloque(const int& size);
        ~Bloque();
        
        const int& getSize();

    friend std::ostream& operator<< (std::ostream& os, Bloque &bloque);
};
