
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

using namespace std;
class Board
{
protected:
    string **board;
    static const int nb_lignes = 10;
    static const int nb_colonnes = 12;

public:
    Board();
    Board(const Board &other);
    void affiche();
    bool placeJeton(int col, string couleur);
    bool checkWin(string couleur);
    int getNbLignes();
    int getNbColonnes();
    string getJeton(int i, int j);
    bool isValidMove(int col) const;
};
#endif

