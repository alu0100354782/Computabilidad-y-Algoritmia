#include "../include/Nfa.hpp"
#include <cstdlib>
#include <istream>

/**
 * @brief Función principal
 *
 * @return int
 */
int main() {

	Nfa nfa;
	cout << endl << endl;

	int option;
	bool nfaloaded = false;
	string str;

	do {

		cout << "  ******************************************************************" << endl;
		cout << "  |                                                                |" << endl;
		cout << "  | COMPUTABILIDAD Y ALGORITMIA                                    |" << endl;
		cout << "  |                                                                |" << endl;
		cout << "  | Sergio Reyes de León                                           |" << endl;
		cout << "  |                                                                |" << endl;
		cout << "  | Práctica #07: Simulación de autómatas finitos no deterministas |" << endl;
		cout << "  |                                                                |" << endl;
		cout << "  ******************************************************************" << endl << endl;
		cout << "\t[1] Leer NFA" << endl;
		cout << "\t[2] Mostrar NFA" << endl;
		cout << "\t[3] Identificar estados de muerte" << endl;
		cout << "\t[4] Identificar estados importantes" << endl;
		cout << "\t[5] Es DFA" << endl;
		cout << "\t[6] Analizar cadena" << endl;
		cout << "\t[7] Salir" << endl << endl;

		cin >> option;
		string nfile;
		cout << endl;

		switch(option) {
			case 1:
				nfa.clear();
				cout << endl << "Nombre fichero: ";
				cin >> nfile;
				cout << endl;
				nfaloaded = nfa.read_nfa("nfas/" + nfile);
				break;

			case 2:
				if(nfaloaded) {
					cout << nfa << endl;					
					cout << "Σ = " << nfa.get_alphabet() << endl;
				}
				else
					cout << "No hay NFA cargado" << endl;
				break;

			case 3:
				if(nfaloaded) {
					set<State> ds = nfa.get_death_states();
					if(ds.size() > 0) {
						cout << "El NFA tiene estados de muerte: ";
						cout << "{";
						int i = 0;
						for (auto s: ds) {
							cout << s.getid();
							if(i < ds.size()-1)
								cout << ", ";
							i++;
						}
						cout << "}" << endl;
					}
					else
						cout << "El NFA NO tiene estados de muerte" << endl;
					}
				else
					cout << "No hay NFA cargado" << endl;
				break;

			case 4:
				if(nfaloaded) {
					set<State> is = nfa.get_important_states();
					if(is.size() > 0) {
						cout << "Estados importantes del NFA: ";
						cout << "{";
						int i = 0;
						for (auto s: is) {
							cout << s.getid();
							if(i < is.size()-1)
								cout << ", ";
							i++;
						}
						cout << "}" << endl;
					}
				}
				else
					cout << "No hay NFA cargado" << endl;
				break;

			case 5:
				if(nfaloaded) {
					if (nfa.is_dfa())
						cout << "El NFA cargado es un DFA" << endl;	
					else
						cout << "El NFA cargado NO es un DFA" << endl;	
				}
				else
					cout << "No hay NFA cargado" << endl;
				break;

			case 6:
				if(nfaloaded) {
					cout << "Cadena de entrada: ";
					cin >> str;
					nfa.check_string(str);
				}
				else
					cout << "No hay NFA cargado" << endl;
				break;

			default:
				break;

		}//end switch

		cout << endl;


	}while(option != 7);

	return 0;
}
