#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "Board.h"
#include "Joueur.h"

using namespace std;

class Game
{
private:
    double score;
    Board board;
    Joueur joueurs[2];
    int indexJoueur;

public:
    Game(const string &j1name, const string &j2name);
    Game(const string &j1name);
    Game() = default;
    void start();
};

#endif

