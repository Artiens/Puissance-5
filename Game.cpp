#include "Game.h"
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

using namespace std;

Game::Game(const string &j1name, const string &j2name) : board()
{
    joueurs[0] = Joueur(j1name, "X");
    joueurs[1] = Joueur(j2name, "O");
    indexJoueur = 0;
}
int colonneValide(){
    int colonne;
    bool isNumeric = false;
    while (!isNumeric) {
        cout << "Entrez l'index de la colonne où vous voulez jouer à partir de l'index 0 : ";
        string input;
        cin >> input;

        try {
            colonne = std::stoi(input);
            isNumeric = true;
        } catch (...) {
            cout << "Erreur : Veuillez entrer un nombre valide." << endl;
            // Effacer le flux d'entrée pour éviter les boucles infinies en cas d'entrée incorrecte
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return colonne;
}
void Game::start()
{
    bool fin = false;
    while (!fin)
    {
        board.affiche();
        cout << "C'est au tour de : " << joueurs[indexJoueur].getName() << endl;
        int colonne=0;

        if (joueurs[indexJoueur].getName() == "AI")
        {
            cout << "Test6" << endl;
            colonne = joueurs->getAI().bestMove(board, 2);
            cout << "Test3" << endl;
        }
        else
        {
            colonne = colonneValide();
        }
        if (board.placeJeton(colonne, joueurs[indexJoueur].getJeton()))
        {
            if (board.checkWin(joueurs[indexJoueur].getJeton()))
            {
                board.affiche();
                cout << "Felicitation, " << joueurs[indexJoueur].getName() << " a gagne!" << endl;
                fin = true;
            }
            else
            {
                indexJoueur = (indexJoueur + 1) % 2;
            }
        }
        else
        {
            cout << "Colonne pleine ou invalide, veuillez choisir une autre colonne..." << endl;
        }
    }
}

