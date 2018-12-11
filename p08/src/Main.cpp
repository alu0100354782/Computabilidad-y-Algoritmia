/*****************************************************************

                    SERGIO REYES DE LEÓN

CyA | Práctica #08: Minimización de estados DFA

*****************************************************************/

#include "../include/Dfa.hpp"


int main(int argc, char *argv[]) {

    Dfa dfa;
    cout << endl << endl;

    int option;
    bool dfaloaded = false;
    string str;

    do {
      cout << "\t[1] Leer DFA" << endl;
      cout << "\t[2] Mostrar DFA" << endl;
      cout << "\t[3] Identificar estados de muerte" << endl;
      cout << "\t[4] Analizar cadena" << endl;
      cout << "\t[5] Minimizar DFA" << endl;
      cout << "\t[6] Exportar DFA" << endl;
      cout << "\t[7] Salir" << endl << endl;

      cin >> option;
      string nfile;

      system("clear");
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
            cout << dfa << endl;
            cout << "Σ = " << dfa.get_alphabet() << endl << endl;
          }
          else
            cout << "No hay DFA cargado" << endl;
          break;

          case 3: 
            if(dfaloaded) {
                set<State> ds = dfa.get_death_states();
                if(ds.size() > 0) {
                    cout << "El DFA tiene estados de muerte: ";
                    cout << "{";
                    int i = 0;
                    for (auto s: ds) {
                        cout << s.getid();
                        if(i < ds.size()-1)
                            cout << ", ";
                        i++;
                    }
                    cout << "}" << endl << endl;
                }
                else
                    cout << "El DFA NO tiene estados de muerte" << endl;
                }
            else
                cout << "No hay DFA cargado" << endl;
            break;
          
          case 4:
            cout << "Cadena de entrada: ";
            cin >> str;
            dfa.check_string(str);

            break;
          case 5:
            break;
          case 6:
            break;

      }//end switch

    }while(option != 7);

    return 0;
}
