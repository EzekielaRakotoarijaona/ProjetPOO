#ifndef ACHETEUR_H_INCLUDED
#define ACHETEUR_H_INCLUDED
#include <iostream>
#include <string>
Class Acheteur: public Client{
protected:
 vector <int> prix;
 vector <bool> proposition;
 vector <int> visite;

public:
    Acheteur(std::string _nom, std::string _adresse, vector<int> _prix, vector<bool> _proposition, vector<int> _visite): Client(_nom, _adresse) {prix = _prix; proposition = _proposition; visite = _visite;};

    //Fonction d'ajout d'une nouvelle visite
    inline void visite( int prix, bool proposition, int idbien ){    visite.push_back(idbien);    visite.push_back( proposition);    visite.push_back(prix);    };

    //fonction pour consulter toutes les visites
    inline vector<int> ConsultVisite()    {      return visite;    };

    // fonction proposition d'une nouvelle visite
    inline bool Proposition(int idbien, int prix)
    { int i;
     for ( i= 0, i< visite.size(), i++)
      if (i = idvisite){
       visite[i] = idvisite;
       proposition[i] = true;
       prix[i] = prix;
     }
    };

    //destructeur
    inline ~Acheteur () {};
};

#endif // ACHETEUR_H_INCLUDED
