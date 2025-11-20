#include "gestor_claves.h"
#include <fstream>
#include <iostream>

void guardarClaves(const std::vector<int>& claves, const std::string& nombreArchivo) {
    std::ofstream ofs(nombreArchivo);
    if (!ofs) {
        std::cerr << "Error al abrir para escribir claves: " << nombreArchivo << "\n";
        return;
    }
    for (size_t i = 0; i < claves.size(); ++i) {
        ofs << claves[i];
        if (i + 1 < claves.size()) ofs << ' ';
    }
    // flush/close automático en destructor
}

std::vector<int> cargarClaves(const std::string& nombreArchivo) {
    std::vector<int> claves;
    std::ifstream ifs(nombreArchivo);
    if (!ifs) {
        std::cerr << "Error al abrir para leer claves: " << nombreArchivo << "\n";
        return claves;
    }
    int v;
    while (ifs >> v) claves.push_back(v);
    return claves;
}
