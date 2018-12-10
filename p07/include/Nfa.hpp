#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include "State.hpp"
#include "Alphabet.hpp"

using namespace std;

/**
 * @brief Representa un NFA.
 * Autómata Finito No Determinista
 * 
 */
class Nfa {

	private:
		unsigned int nstates_;	// número de estados
		set<State> q_;			// conjunto de estados
		unsigned int s_;		// estado inicial
		State current_;       	// estado actual		
		Alphabet alphabet_;		// alfabeto

	public:
		Nfa();				// constructor por defecto
		Nfa(const Nfa&);	// constructor de copia
		~Nfa();				// destructor

		void clear();
		bool read_nfa(const string&);             		// leer NFA
		const set<State>& getallstates();         		// obtener todos los estados
		const set<State> get_death_states() const;		// obtener estados de muerte
		const set<State> get_important_states() const; 	// obtener estados importantes
		bool check_string(const string&);         		// comprobar cadena
		const Alphabet get_alphabet() const;			// obtener alfabeto del NFA
		bool is_dfa() const;							// comprobar si es DFA
		const set<State> epsilon_closure();	// epsilon clausura del estado actual

		/*Implementar función transitar para usar recursivamente

			transitar(string cadena, int indice, State estado_actual)
		*/

	//sobrecarga de la salida
	friend ostream& operator << (ostream& os, const Nfa& nfa);
};
