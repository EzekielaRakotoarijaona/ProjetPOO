#include <iostream>
#include <string>
Cass Acheteur: public Client{
protected:

 int prix;
 bool proposition;
 vector <int> Achat;

public:
    Acheteur::Acheteur();
    void NouvelleVisite (Biens &bien, int prix, );
    void ConsultVisite (Biens &bien);
    bool Proposition (Biens &bien, int prix )
    ~Acheteur ();
};
