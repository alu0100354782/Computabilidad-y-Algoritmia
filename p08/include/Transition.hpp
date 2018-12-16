#pragma once

#include <iostream>


using namespace std;

class Transition {

    private:
        char symbol_;           //símbolo entrante
        unsigned int tostate_;  //estado al que se transita

    public:
        Transition();
        Transition(char, unsigned int);
        Transition(const Transition& t);

        const char& getsymbol();
        const unsigned int& gettostate();

        void setsymbol(char&);
        void settostate(int&);
        
        
        Transition& operator=(const Transition &rhs);
		int operator==(const Transition &rhs) const;
		int operator<(const Transition &rhs) const;

        friend ostream& operator << (ostream&, const Transition&);
};
