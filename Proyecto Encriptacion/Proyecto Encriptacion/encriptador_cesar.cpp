#include "encriptador.h"
#include "gestor_claves.h"

#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include <cctype>
#include <iostream>

std::string cifrarCesarClaveAleatoria(const std::string& texto, const std::string& nombreArchivoClaves) {
    std::ostringstream out;
    std::vector<int> claves;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (char c : texto) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            int clave = std::rand() % 26 + 1; // 1..26
            claves.push_back(clave);
            char base = std::islower(static_cast<unsigned char>(c)) ? 'a' : 'A';
            char cif = static_cast<char>((c - base + clave) % 26 + base);
            out << cif;
        }
        else {
            // Para mantener la correspondencia de posiciones (si queremos una clave por carácter),
            // guardamos 0 para caracteres no-alfa.
            claves.push_back(0);
            out << c;
        }
    }

    guardarClaves(claves, nombreArchivoClaves);
    return out.str();
}

std::string descifrarCesarConArchivo(const std::string& texto, const std::string& nombreArchivoClaves) {
    std::vector<int> claves = cargarClaves(nombreArchivoClaves);
    if (claves.empty()) {
        std::cerr << "No hay claves cargadas (archivo vacío o no encontrado).\n";
        return std::string{};
    }
    if (claves.size() != texto.size()) {
        std::cerr << "Advertencia: número de claves (" << claves.size()
            << ") distinto de longitud de texto (" << texto.size() << ").\n";
        // Próximo: intentamos descifrar hasta la longitud mínima
    }

    std::ostringstream out;
    size_t n = std::min(claves.size(), texto.size());
    for (size_t i = 0; i < n; ++i) {
        char c = texto[i];
        int clave = claves[i];
        if (clave > 0 && std::isalpha(static_cast<unsigned char>(c))) {
            char base = std::islower(static_cast<unsigned char>(c)) ? 'a' : 'A';
            char dec = static_cast<char>((c - base - clave + 26) % 26 + base);
            out << dec;
        }
        else {
            out << c;
        }
    }
    // Si el texto es más largo que claves, append resto sin modificar
    if (texto.size() > n) out << texto.substr(n);
    return out.str();
}
