#ifndef ACHETEUR_H
#define ACHETEUR_H
#include <iostream>
#include <vector>
#include "client.h"


class Acheteur: public Client{
// Attributs de la classe acheteur
protected:
 std::vector <int> prix;
 std::vector <bool> proposition;
 std::vector <int> idbien;

 //Méthode classe acheteur
public:
    Acheteur(std::string _nom, std::string _adresse);
    void ajouter_visite(int _prix, bool _proposition, int _idbien); //Méthode ajouter visite
    void afficher_acheteur();//Méthode afficher acheteur
    void afficher_visites();//Méthode afficher visites 
    inline ~Acheteur () {}; //destructeur
};

#endif
