#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo
int ejemplo6(const int n)
{ 
  // codigo fuente de cada bloque
  int suma = 0;  // (1)
  for (int i = 1; i <= n; i *= 2)  // Θ(log n)
    for (int j = 1; j <= i; j++)  // Θ(i)
      suma++;  // (1)
  return suma;
}

int main()
{ // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;

  // invocar a cada ejemplo
  cout << "Ejemplo 6: " << ejemplo6(n) << endl;
  return 0;
}
