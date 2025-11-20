#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H

#include <string>
#include <vector>

// César (polialfabético: clave por letra) - guarda/lee claves desde archivo
std::string cifrarCesarClaveAleatoria(const std::string& texto, const std::string& nombreArchivoClaves = "claves_cesar.txt");
std::string descifrarCesarConArchivo(const std::string& texto, const std::string& nombreArchivoClaves = "claves_cesar.txt");

// XOR
std::string cifrarXOR(const std::string& texto, char clave);
std::string descifrarXOR(const std::string& texto, char clave);

// ROT13
std::string cifrarROT13(const std::string& texto);
std::string descifrarROT13(const std::string& texto);

#endif // ENCRIPTADOR_H
