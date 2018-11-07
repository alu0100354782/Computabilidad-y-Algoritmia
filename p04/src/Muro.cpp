#include "../include/Muro.hpp"
#include <math.h>

Muro::Muro(const int &ancho, const int &alto) {
    setDimension(ancho, alto);
    
    for(int i = 0; i < alto; i++) {
        int ancho_aux = ancho;
        Fila fila;
        for(int j = 0; j <= ancho_aux+1; j++) {
            Bloque b;

            if(ancho_aux-3 < 0) 
                b = Bloque(2);
            else 
                b = Bloque(3);
            
            fila.ponerBloque(i,b);
            ancho_aux -= b.getAncho();
        }
        setFila(fila);
    }
}

Muro::Muro(const Muro &muro) {
    *this = muro;
}

Muro::~Muro() { }

void Muro::setDimension(const int &ancho, const int &alto) {
    _ancho = ancho;
    _alto = alto;
}

const Fila& Muro::getFila(const int &i) {
    return _filas[i];
}

void Muro::setFila(const Fila &fila) {
    _filas.push_back(fila);
}

/**
 * @brief Genera todas las combinaciones de fila posibles para el ancho del muro
 * 
 * @param fila 
 * @param ancho_actual 
 */
void Muro::generarFilas(Fila& fila, int &ancho_actual) {
        
    int nFila = 0;        

    if(ancho_actual + 1 < _ancho) {
        
        Bloque b3(3);
        fila.ponerBloque(nFila, b3);
        ancho_actual += 3;
        generarFilas(fila, ancho_actual);

        Bloque b2(2);
        fila.ponerBloque(nFila, b2);
        ancho_actual += 2;
        generarFilas(fila, ancho_actual);    

        // if( std::find(_fposibles.begin(), _fposibles.end(), fila) != _fposibles.end() )
            _fposibles.push_back(fila);
    }
    ancho_actual = 0;
    
}

/**
 * @brief Comprueba que es un muro bien construido
 * 
 */
void Muro::comprobar() {
    // for( Fila f: _filas)
        //
}

std::ostream& operator<< (std::ostream& os, Muro &muro) {
    for (Fila f : muro._filas) 
        os << f << std::endl;
    
    return os;
}