#ifndef GESTOR_CLAVES_H
#define GESTOR_CLAVES_H

#include <vector>
#include <string>

void guardarClaves(const std::vector<int>& claves, const std::string& nombreArchivo);
std::vector<int> cargarClaves(const std::string& nombreArchivo);

#endif // GESTOR_CLAVES_H
