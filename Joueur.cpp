#include "Joueur.h"
#include <iostream>
#include <string>
using namespace std;

Joueur::Joueur(string nom, string jeton) : nom(nom), jeton(jeton), score(0)
{
}
void Joueur::afficheScore()
{
    cout << nom << " possede : " << score << " points." << endl;
}
string Joueur::getName() const
{
    return nom;
}
string Joueur::getJeton() const
{
    return jeton;
}
AI Joueur::getAI()
{
    return ai;
}
