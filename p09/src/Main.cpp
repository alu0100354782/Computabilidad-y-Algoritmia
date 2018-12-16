/*****************************************************************

                    SERGIO REYES DE LEÓN

CyA | Práctica #09: Gramática regular a partir de un DFA

*****************************************************************/

/**
 * @file Main.cpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @date 2018-12-16
 * @version 0.1
 * @brief  Fichero que contiene la función main del programa
 *
 * @copyright Copyright (c) 2018
 *
 */

#include "../include/Dfa.hpp"
#include "../include/Grammar.hpp"

/**
 * @brief Función principal del programa
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{

    if (argc == 3)
    {
        Dfa dfa;
        dfa.read_dfa(argv[1]);

        Grammar grammar(dfa);
        grammar.to_file(argv[2]);
        cout << endl;

        ifstream f((string)argv[2]);

        if (f.is_open())
            cout << f.rdbuf();
    }
    else
    {
        // cout << "El programa necesita dos parámetros, nombre_fichero_dfa nombre_ficher_gramatica" << endl;
        Dfa dfa;
        cout << endl
             << endl;

        int option = 0;
        bool dfaloaded = false;
        string str;

        do
        {
            cout << "  ******************************************************" << endl;
            cout << "  |                                                    |" << endl;
            cout << "  | COMPUTABILIDAD Y ALGORITMIA                        |" << endl;
            cout << "  |                                                    |" << endl;
            cout << "  | Sergio Reyes de León                               |" << endl;
            cout << "  |                                                    |" << endl;
            cout << "  | Práctica #09: Gramática regular a partir de un DFA |" << endl;
            cout << "  |                                                    |" << endl;
            cout << "  ******************************************************" << endl
                 << endl;
            cout << "\t[1] Leer DFA" << endl;
            cout << "\t[2] Mostrar DFA" << endl;
            cout << "\t[3] Obtener Gramática Regular" << endl;
            cout << "\t[4] Salir" << endl
                 << endl;

            cin >> option;
            string nfile;

            system("clear");
            switch (option)
            {
            case 1:
                dfa.clear();
                cout << endl
                     << "Nombre fichero: ";
                cin >> nfile;
                cout << endl;
                dfaloaded = dfa.read_dfa("dfas/" + nfile);
                break;

            case 2:
                cout << endl;
                if (dfaloaded)
                {
                    cout << dfa << endl;
                    cout << "Σ = " << dfa.get_alphabet() << endl
                         << endl;
                }
                else
                    cout << "No hay DFA cargado" << endl;
                break;

            case 3:
            {
                string filegrammar = "";
                cout << "Nombre del fichero donde se va a guardar la gramática: ";
                cin >> filegrammar;

                Grammar grammar(dfa);
                grammar.to_file("grms/" + filegrammar);

                system("clear");

                cout << grammar << endl;
                break;
            }
            default:
                break;
            }

        } while (option != 4);

        return 0;
    }
}
