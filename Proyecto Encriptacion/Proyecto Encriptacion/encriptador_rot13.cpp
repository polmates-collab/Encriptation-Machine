#include "encriptador.h"
#include <cctype>
#include <string>

std::string cifrarROT13(const std::string& texto) {
    std::string res = texto;
    for (char& c : res) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            char base = std::islower(static_cast<unsigned char>(c)) ? 'a' : 'A';
            c = static_cast<char>((c - base + 13) % 26 + base);
        }
    }
    return res;
}

std::string descifrarROT13(const std::string& texto) {
    return cifrarROT13(texto); // simétrico
}
