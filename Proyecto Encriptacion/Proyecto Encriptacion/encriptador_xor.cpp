#include "encriptador.h"
#include <string>

std::string cifrarXOR(const std::string& texto, char clave) {
    std::string res = texto;
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] = static_cast<char>(static_cast<unsigned char>(res[i]) ^ static_cast<unsigned char>(clave));
    }
    return res;
}

std::string descifrarXOR(const std::string& texto, char clave) {
    // XOR reversible con misma operación
    return cifrarXOR(texto, clave);
}
