#include <iostream>
#include <chrono>
#include "../include/Muro.hpp"

using namespace std;

int main() {
    
    chrono::time_point<std::chrono::system_clock> inicio, fin; 

    inicio = chrono::system_clock::now();

    int ancho, alto;

    cout << "COMPUTABILIDAD Y ALGORITMIA" << endl;
    cout << "Práctica #04: Construyendo un muro" << endl << endl;

    cout << "Dimensiones del muro:" << endl;
    cout << "Ancho = ";
    cin >> ancho;
    cout << "Alto = ";
    cin >> alto;    

    Muro m(ancho, alto);

    Fila empty;
    int ancho_actual = 0;
    
    // m.generarFilas(empty, ancho_actual);
    // m.comprobar();

    std::vector<Muro> _muros; // muros bien construidos

    cout << endl << m << endl;

    fin = std::chrono::system_clock::now(); 
  
    chrono::duration<double> elapsed_seconds = fin - inicio; 
    time_t tiempo_final = chrono::system_clock::to_time_t(fin); 
  
    std::cout << "el tiempo de computación finalizó a " << std::ctime(&tiempo_final) 
              << "tiempo transcurrido: " << elapsed_seconds.count() << "s\n"; 


    return 0;
}