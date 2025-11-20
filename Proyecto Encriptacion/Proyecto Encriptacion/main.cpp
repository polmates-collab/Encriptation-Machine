#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "encriptador.h"

void mostrarMenu() {
    std::cout << "\n=== SISTEMA DE ENCRIPTACIÓN ===\n";
    std::cout << "1. Cifrar con César (clave aleatoria por letra, guarda archivo)\n";
    std::cout << "2. Descifrar con César (lee archivo de claves)\n";
    std::cout << "3. Cifrar con XOR\n";
    std::cout << "4. Descifrar con XOR\n";
    std::cout << "5. Cifrar con ROT13\n";
    std::cout << "6. Descifrar con ROT13\n";
    std::cout << "0. Salir\n";
    std::cout << "Opción: ";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int opcion = -1;
    std::string texto;
    char claveXOR;

    do {
        mostrarMenu();
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada inválida.\n";
            continue;
        }
        std::cin.ignore(10000, '\n'); // limpiar buffer

        switch (opcion) {
        case 1:
            std::cout << "Introduce el texto a cifrar: ";
            std::getline(std::cin, texto);
            std::cout << "Nombre archivo de claves (o ENTER para 'claves_cesar.txt'): ";
            {
                std::string nombre;
                std::getline(std::cin, nombre);
                if (nombre.empty()) nombre = "claves_cesar.txt";
                std::string cif = cifrarCesarClaveAleatoria(texto, nombre);
                std::cout << "Texto cifrado: " << cif << "\n";
                std::cout << "Claves guardadas en: " << nombre << "\n";
            }
            break;

        case 2:
            std::cout << "Introduce el texto cifrado: ";
            std::getline(std::cin, texto);
            std::cout << "Nombre archivo de claves (o ENTER para 'claves_cesar.txt'): ";
            {
                std::string nombre;
                std::getline(std::cin, nombre);
                if (nombre.empty()) nombre = "claves_cesar.txt";
                std::string dec = descifrarCesarConArchivo(texto, nombre);
                std::cout << "Texto descifrado: " << dec << "\n";
            }
            break;

        case 3:
            std::cout << "Introduce el texto a cifrar: ";
            std::getline(std::cin, texto);
            std::cout << "Introduce la clave (carácter): ";
            std::cin.get(claveXOR);
            std::cin.ignore(10000, '\n');
            std::cout << "Texto cifrado: " << cifrarXOR(texto, claveXOR) << "\n";
            break;

        case 4:
            std::cout << "Introduce el texto a descifrar: ";
            std::getline(std::cin, texto);
            std::cout << "Introduce la clave (carácter): ";
            std::cin.get(claveXOR);
            std::cin.ignore(10000, '\n');
            std::cout << "Texto descifrado: " << descifrarXOR(texto, claveXOR) << "\n";
            break;

        case 5:
            std::cout << "Introduce el texto a cifrar (ROT13): ";
            std::getline(std::cin, texto);
            std::cout << "Texto cifrado: " << cifrarROT13(texto) << "\n";
            break;

        case 6:
            std::cout << "Introduce el texto a descifrar (ROT13): ";
            std::getline(std::cin, texto);
            std::cout << "Texto descifrado: " << descifrarROT13(texto) << "\n";
            break;

        case 0:
            std::cout << "Saliendo...\n";
            break;

        default:
            std::cout << "Opción no válida.\n";
        }

    } while (opcion != 0);

    return 0;
}
