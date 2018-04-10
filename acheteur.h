#include <iostream>
#include <string>
Class Acheteur: public Client{
protected:

 vector <int> prix;
 vector <bool> proposition;
 vector <int> Achat;

public:
    Acheteur::Acheteur(int prix, bool proposition);
    bool NouvelleVisite (Biens &bien, int prix);
    tab ConsultVisite ();
    bool Proposition (Biens &bien, int prix);
    ~Acheteur ();
};
