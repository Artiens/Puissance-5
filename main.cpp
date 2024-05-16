#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Joueur.h"
using namespace std;

int main()
{
    cout << "Saisissez le nom du Joueur 1." << endl;
    string j1;
    cin >> j1;
    cout << "Jouer contre une IA ? (O/N)" << endl;
    cin.clear();
    string choix = "";
    cin >> choix;
    cin.clear();

    string j2;

    Game game;

    if (choix == "O")
    {
        game = Game(j1, "AI");
    }
    else
    {
        cout << "Saisissez le nom du Joueur 2." << endl;
        cin >> j2;
        cin.clear();

        game = Game(j1, j2);
    }

    game.start();

    return 0;
}
