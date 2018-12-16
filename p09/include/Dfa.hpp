/**
 * @file Dfa.hpp
 * @Author Sergio Reyes de León (alu0100354782@ull.edu.es)
 * @date 2018-12-16
 * @version 0.1
 * @brief Fichero que contiene la clase Dfa
 *
 * @copyright Copyright (c) 2018
 *
 */
#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include "State.hpp"
#include "Alphabet.hpp"

using namespace std;

/**
 * @brief Representa un DFA.
 * Autómata Finito Determinista
 *
 */
class Dfa {

	private:
		unsigned int nstates_;  // número de estados
		set<State> q_;	        // colección de estados
		unsigned int s_;        // estado inicial
		State current_;         // estado actual
		Alphabet alphabet_;     // alfabeto


	public:
		Dfa();
		Dfa(const Dfa&);
		~Dfa();

		const unsigned int& get_s();    // Obtener id estado inicial

		void clear();
		void reset();
		bool read_dfa(const string&);       // leer dfa
		void save_dfa(const string&);       // guardar dfa
		const set<State>& getallstates();   // obtener todos los estados
		const set<State> get_death_states();// obtener estados de muerte
		bool check_string(const string&);   // comprobar cadena
		const Alphabet get_alphabet() const;

		void minimize();    // minimizar DFA
		const set<set<State>> new_partition(set<set<State>>&, int&);
		const set<set<State>> factorize(set<State>&, set<set<State>>&, int&);
		const set<set<State>> split(set<State>&, char&, set<set<State>>&);
		void print_set_states(set<set<State>>&, int&, char&, set<State>&, set<set<State>>&);


		friend ostream& operator << (ostream& os, const Dfa& dfa); // salida

};
