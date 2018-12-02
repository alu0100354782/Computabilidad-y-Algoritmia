/*****************************************************************

                    SERGIO REYES DE LEÓN

CyA | Práctica #06: Simulación de autómatas finitos deterministas

*****************************************************************/

#include "../include/Dfa.hpp"
#include <cstdlib>
#include <istream>


int main() {

    Dfa dfa;
    cout << endl << endl;

    int option;
    bool dfaloaded = false;
    string str;  
    
    do {            

      cout << "***************************************************************" << endl;
      cout << "|                                                             |" << endl;
      cout << "| COMPUTABILIDAD Y ALGORITMIA                                 |" << endl;
      cout << "|                                                             |" << endl;
      cout << "| Sergio Reyes de León                                        |" << endl;
      cout << "|                                                             |" << endl;
      cout << "| Práctica #06: Simulación de autómatas finitos deterministas |" << endl;
      cout << "|                                                             |" << endl;
      cout << "***************************************************************" << endl << endl;
      cout << "\t[1] Leer DFA" << endl;
      cout << "\t[2] Mostrar DFA" << endl;
      cout << "\t[3] Identificar estados de muerte" << endl;
      cout << "\t[4] Analizar cadena" << endl;
      cout << "\t[5] Salir" << endl << endl;

      cin >> option;
      string nfile;            

      switch(option) {
        case 1:
          dfa.clear();
          cout << endl << "Nombre fichero: ";
          cin >> nfile;
          cout << endl;
          dfaloaded = dfa.read_dfa("dfas/" + nfile);
          break;

        case 2:
          cout << endl;
          if(dfaloaded) {
            cout << dfa;
            cout << "Tamaño del alfabeto: " << dfa.get_alphabet().size() << endl;
          }
          else
            cout << "No hay DFA cargado" << endl;
          break;

          case 3: {
            cout << endl;
            set<State> ds = dfa.get_death_states();
            if(ds.size() > 0) {
              cout << "El DFA tiene estados de muerte: ";
              for (auto s: ds)
                cout << s.getn() << " ";
            }
            else
              cout << "El DFA NO tiene estados de muerte" << endl;
            break;
          }
          case 4:
            cout << "Cadena de entrada: ";
            cin >> str;
            dfa.check_string(str);

            break;

      }//end switch

      cout << endl;


    }while(option != 5);

    return 0;
}
