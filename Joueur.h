#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include "AI.h"

using namespace std;

class Joueur
{
private:
    string jeton;
    string nom;
    double score;
    AI ai = AI(jeton);

public:
    Joueur(string nom, string jeton);
    Joueur() = default;
    void afficheScore();
    string getName() const;
    string getJeton() const;
    AI getAI();
};

#endif

