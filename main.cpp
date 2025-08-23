#include "List.hpp"
#include "Actions.hpp"
#include "functions.hpp"

#include <cstdlib>
#include <ncurses.h>


int main() 
{
    std::system("clear");
    List<int>* MyList = new List<int>();
    while (continuer()) 
    {
        menu_principal();
        char choice = '\0';
        std::cout << "FAITE VOTRE CHOIX.";
        std::cout << ">_ ";

        std::cin >> choice;

        switch (choice) {
            case '1':
                ajouter_une_valeur(MyList);
                break;
            case '2':
                supprimer(MyList);
            case '3':
                afficher_la_liste(MyList);
            default:
                std::cerr << "Choix non disponible.\n";
        }
    }
    delete MyList;
    return 0;
}
