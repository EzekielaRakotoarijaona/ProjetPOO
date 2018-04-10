#ifndef ACHETEUR_H
#define ACHETEUR_H
#include <iostream>
#include <vector>
#include "client.h"

class Acheteur: public Client{
protected:
 std::vector <int> prix;
 std::vector <bool> proposition;
 std::vector <int> idbien;

public:
    Acheteur(std::string _nom, std::string _adresse, std::vector<int> _prix, std::vector<bool> _proposition, std::vector<int> _idbien);
    void visite(int _prix, bool _proposition, int _idbien);
    void proposer_visite(int _idbien, int _prix);
    void afficher();
    inline ~Acheteur () {}; //destructeur
};

#endif
