#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo
int ejemplo4(const int n)
{ 
  // codigo fuente de cada bloque
  int suma = 0;  // Θ(1)
  for (int i = 1; i <= n; i++)  // Θ(n)
  for (int j = 1; j <= i; j++)  // Θ(i)
    suma++;  // Θ(1)
  return suma;
}

int main()
{ // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;

  // invocar a cada ejemplo
  cout << "Ejemplo 4: " << ejemplo4(n) << endl;
  return 0;
}
