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

 //Methode classe acheteur
public:
    Acheteur(std::string _nom, std::string _adresse);
    void ajouter_visite(int _prix, bool _proposition, int _idbien);
    void afficher_acheteur();
    void afficher_visites();
    inline ~Acheteur () {}; //destructeur
};

#endif
