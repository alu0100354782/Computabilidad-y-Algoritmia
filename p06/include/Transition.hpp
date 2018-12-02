#pragma once

#include <iostream>


using namespace std;

class Transition {

    private:
        char symbol_;           //símbolo entrante
        unsigned int toState_;  //estado al que se transita

    public:
        Transition();
        Transition(char, unsigned int);
        Transition(const Transition& t);

        const char& getsymbol();
        const unsigned int& gettoState();

        void setsymbol(char&);
        void settoState(int&);


        Transition& operator=(const Transition &t);
        int operator==(const Transition &t) const;
        int operator<(const Transition &t) const;

    friend ostream& operator << (ostream&, const Transition&);
};
