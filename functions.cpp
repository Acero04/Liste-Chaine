#include "functions.hpp"

#include <iostream>

bool continuer() {
    char c = '\0';
    std::cout << "'c' pour continuer.\n";
    std::cout << "'q' pour sortir.\n";
    std::cout << "Voulez vous continuer ?.\n";


    do {
        std::cout << ">_ ";
        std::cin >> c;
    }while (c != 'c' && c != 'q');

    return c == 'c';
}
//
void menu_principal() {
    std::cout << "1. pour creer un nouveau maillon dans la liste.\n";
    std::cout << "2. pour supprimer un maillon dans la liste.\n";
    std::cout << "3. pour afficher la liste.\n";
}
