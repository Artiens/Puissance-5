#ifndef AI_H
#define AI_H
#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

class AI
{
private:
    string jeton;
    string name = "AI";
    string jetonAdv;
    int minimax(Board board, int profondeur, bool maximizingPlayer);
    int evaluate(Board board);
    int alignement(Board, string couleur);
    int length(Board board, int ligne, int colonne, string couleur);

public:
    AI(string jeton);
    int bestMove(Board board, int profondeur);
};

#endif

