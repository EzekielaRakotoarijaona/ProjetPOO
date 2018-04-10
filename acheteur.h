#include <iostream>
#include <string>
Class Acheteur: public Client{
protected:

 vector <int> prix;
 vector <bool> proposition;
 vector <int> Achat;

public:
    Acheteur::Acheteur(int prix, bool proposition);
    bool NouvelleVisite (int bien, int prix);
    tab ConsultVisite ();
    bool Proposition (int bien, int prix);
    ~Acheteur ();
};
