#ifndef ACHETEUR_H_INCLUDED
#define ACHETEUR_H_INCLUDED
#include <iostream>
#include <vector>
#include "client.h"

Class Acheteur: public Client{
protected:
 vector <int> prix;
 vector <bool> proposition;
 vector <int> visite;

public:
    Acheteur(std::string _nom, std::string _adresse, vector<int> _prix, vector<bool> _proposition, vector<int> _visite): Client(_nom, _adresse);
    void visite(int prix, bool proposition, int idbien);  //Fonction d'ajout d'une nouvelle visite
    vector<int> ConsultVisite();   //fonction pour consulter toutes les visites
    bool Proposition(int idbien, int prix);  // fonction proposition d'une nouvelle visite
    inline ~Acheteur () {}; //destructeur
};

#endif
