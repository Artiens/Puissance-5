#include "AI.h"
#include <iostream>
#include <string>
using namespace std;

AI::AI(string jeton) : jeton(jeton)
{
    if (jeton == "X")
    {
        string jetonAdv = "O";
    }
    else
    {
        string jetonAdv = "X";
    }
}
int AI::minimax(Board board, int profondeur, bool maximizingPlayer)
{

    if (profondeur == 0 || board.checkWin(jeton))
    {
        return evaluate(board); // Évalue la position actuelle
    }

    if (maximizingPlayer)
    {
        int maxEval = -1000;
        for (int col = 0; col < board.getNbColonnes(); ++col)
        {
            if (board.isValidMove(col))
            {
                Board newBoard=board;
                newBoard.placeJeton(col, jeton);
                int eval = minimax(newBoard, profondeur - 1, false);
                maxEval = max(maxEval, eval);
                newBoard.~Board();
            }
        }
        return maxEval;
    }
    else
    {
        int minEval = 1000;
        for (int col = 0; col < board.getNbColonnes(); ++col)
        {
            if (board.isValidMove(col))
            {
                Board newBoard=board;
                newBoard.placeJeton(col, jetonAdv);
                int eval = minimax(newBoard, profondeur - 1, true);
                minEval = min(minEval, eval);
                newBoard.~Board();
            }
        }
        return minEval;
    }
}

int AI::evaluate(Board board)
{

    int score = 0;
    score += alignement(board, jeton);
    score -= alignement(board, jetonAdv);
    return score;
}
int AI::alignement(Board board, string couleur)
{
    int score = 0;
    int maxLineLength = 0;
    for (int i = 0; i < board.getNbLignes(); ++i)
    {
        for (int j = 0; j < board.getNbColonnes(); ++j)
        {
            if (board.getJeton(i, j) == couleur)
            {
                // Recherche des alignements dans les directions horizontale, verticale et diagonale
                int lineLength = length(board, i, j, couleur);
                if (lineLength > maxLineLength)
                {
                    maxLineLength = lineLength;
                }
            }
        }
    }
    // Attribution de scores en fonction de la longueur des alignements
    if (maxLineLength >= 4)
    {
        score = 1000; // Score très élevé pour un alignement gagnant
    }
    else if (maxLineLength == 3)
    {
        score = 100; // Score élevé pour un alignement potentiellement gagnant
    }
    else if (maxLineLength == 2)
    {
        score = 10; // Score moyen pour un alignement potentiel
    }
    else
    {
        score = 1; // Score faible pour une position non stratégique
    }

    return score;
}

int AI::length(Board board, int ligne, int colonne, string couleur)
{
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    int maxLength = 0;

    for (int i = 0; i < 5; ++i)
    {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int length = 1; // Initialiser la longueur à 1 pour le jeton actuel

        // Compter les jetons dans la direction (dx, dy)
        for (int k = 1; k <= 4; ++k)
        { // Parcours jusqu'à 3 jetons maximum dans chaque direction
            int newRow = ligne + k * dx;
            int newCol = colonne + k * dy;

            // Vérifier si la nouvelle position est valide et si elle contient un jeton du joueur
            if (newRow >= 0 && newRow < board.getNbLignes() && newCol >= 0 && newCol < board.getNbColonnes() &&
                board.getJeton(newRow, newCol) == couleur)
            {
                length++;
            }
            else
            {
                break; // Arrêter de parcourir la direction si une case vide ou un jeton adverse est rencontré
            }
        }

        // Compter les jetons dans la direction opposée (-dx, -dy)
        for (int k = 1; k <= 3; ++k)
        {
            int newRow = ligne - k * dx;
            int newCol = colonne - k * dy;

            if (newRow >= 0 && newRow < board.getNbLignes() && newCol >= 0 && newCol < board.getNbColonnes() &&
                board.getJeton(newRow, newCol) == couleur)
            {
                length++;
            }
            else
            {
                break;
            }
        }

        // Mettre à jour la longueur maximale trouvée dans toutes les directions
        if (length > maxLength)
        {
            maxLength = length;
        }
    }

    return maxLength;
}

int AI::bestMove(Board board, int depth)
{
    int bestMove = -1;
    int bestScore = -1000; // Score initial pour maximiser
    for (int col = 0; col < board.getNbColonnes(); ++col)
    {
        if (board.isValidMove(col))
        {
            Board newBoard = board;                       // Copie temporaire du plateau
            newBoard.placeJeton(col, jeton);              // Simule le coup de l'IA
            int score = minimax(newBoard, depth, false); // Appel récursif à MiniMax
            if (score > bestScore)
            {
                bestScore = score;
                bestMove = col;
            }
            newBoard.~Board();
        }
    }
    return bestMove;
}
