#include "Board.h"
#include <iostream>
#include <string>
using namespace std;

Board::Board()
{
    board = new string *[nb_lignes];
    for (int i = 0; i < nb_lignes; i++)
    {
        board[i] = new string[nb_colonnes];
        for (int j = 0; j < nb_colonnes; j++)
        {
            board[i][j] = " ";
        }
    }
}

Board::Board(const Board &other)
{

    board = new string *[nb_lignes];
    for (int i = 0; i < nb_lignes; i++)
    {
        board[i] = new string[nb_colonnes];
        for (int j = 0; j < nb_colonnes; j++)
        {
            board[i][j] = other.board[i][j];
        }
    }
}

void Board::affiche()
{
    for (int i = 0; i < nb_lignes; i++)
    {
        for (int j = 0; j < nb_colonnes; j++)
        {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "--------------------------------------" << endl;
}

bool Board::placeJeton(int col, string couleur)
{
    if (col < 0 || col >= nb_colonnes)
    {
        return false; // Colonne invalide
    }
    for (int i = nb_lignes - 1; i >= 0; --i)
    {
        if (board[i][col] == " ")
        {
            board[i][col] = couleur;
            return true;
        }
    }
    return false; // Colonne pleine
}

bool Board::checkWin(string couleur)
{
    // Test lignes
    for (int i = 0; i < nb_lignes; i++)
    {
        int cnt = 0;
        for (int j = 0; j < nb_colonnes; j++)
        {
            if (board[i][j] == couleur)
            {
                cnt++;
                if (cnt == 5)
                    return true;
            }
            else
            {
                cnt = 0;
            }
        }
    }

    // Test colonnes
    for (int i = 0; i < nb_colonnes; i++)
    {
        int cnt = 0;
        for (int j = 0; j < nb_lignes; j++)
        {
            if (board[j][i] == couleur)
            {
                cnt++;
                if (cnt == 5)
                    return true;
            }
            else
            {
                cnt = 0;
            }
        }
    }

    // Test diagonale descendante
    for (int i = 0; i <= nb_lignes - 5; i++)
    {
        for (int j = 0; j <= nb_colonnes - 5; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 5; k++)
            {
                if (board[i + k][j + k] == couleur)
                {
                    cnt++;
                    if (cnt == 5)
                        return true;
                }
                else
                {
                    cnt = 0;
                }
            }
        }
    }

    // Test diagonale ascendante
    for (int i = 0; i <= nb_lignes - 5; i++)
    {
        for (int j = nb_colonnes - 1; j >= 4; j--)
        {
            int cnt = 0;
            for (int k = 0; k < 5; k++)
            {
                if (board[i + k][j - k] == couleur)
                {
                    cnt++;
                    if (cnt == 5)
                        return true;
                }
                else
                {
                    cnt = 0;
                }
            }
        }
    }

    return false;
}

int Board::getNbLignes()
{
    return nb_lignes;
}

int Board::getNbColonnes()
{
    return nb_colonnes;
}
string Board::getJeton(int i, int j)
{
    return board[i][j];
}

bool Board::isValidMove(int col) const
{
    // Vérifie si la colonne spécifiée est valide
    if (col < 0 || col >= nb_colonnes)
    {
        return false; // Colonne invalide
    }
    // Vérifie si la colonne n'est pas pleine
    return board[0][col] == " ";
}



