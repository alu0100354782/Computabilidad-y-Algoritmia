#include "../include/Alphabet.hpp"

/**
 * @brief Construct a new Alphabet:: Alphabet object
 * Constructor por defecto
 */
Alphabet::Alphabet() { }

/**
 * @brief Construct a new Alphabet:: Alphabet object
 * Constructor de copia
 *
 * @param alphabet Objeto Alphabet a copiar
 */
Alphabet::Alphabet(const Alphabet &alphabet) {
    *this = alphabet;
}

/**
 * @brief Destroy the Alphabet:: Alphabet object
 * Destructor
 */
Alphabet::~Alphabet() { }

/**
 * @brief Obtener conjunto de símbolos del alfabeto
 *
 * @return const set<char>& conjunto de símbolos del alfabeto
 */
const set<char>& Alphabet::getsymbols() {
    return _symbols;
}

/**
 * @brief Establecer conjunto de símbolos del alfabeto
 *
 * @param symbols conjunto de símbolos del alfabeto
 */
void Alphabet::setsymbols(const set<char> &symbols) {
    _symbols = symbols;
}

/**
 * @brief Insertar símbolo
 *
 * @param symbol símbolo
 */
void Alphabet::insert(const char &symbol) {
    _symbols.insert(symbol);
}

/**
 * @brief Vacíar conjunto de símbolos del alfabeto
 *
 */
void Alphabet::clear() {
    _symbols.clear();
}

/**
 * @brief Tamaño del alfabeto
 *
 * @return int tamaño alfabeto
 */
int Alphabet::size() const {
    return _symbols.size();
}

/**
 * @brief Sobrecarga del operador de salida
 *
 * @param os Cadena resultante
 * @param alphabet objeto tipo Alphabet
 * @return ostream& Flujo de salida
 */
ostream& operator << (ostream &os, const Alphabet &alphabet) {
    os << "{";
    int i = 0;
    for (char s: alphabet._symbols) {
        os << s;
        if (i < alphabet._symbols.size() - 1) {
            os << ", ";
        }
        i++;
    }
    os << "}";

    return os;
}