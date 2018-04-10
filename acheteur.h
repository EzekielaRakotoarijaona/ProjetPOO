#include <iostream>
#include <string>
Class Acheteur: public Client{
protected:

 vector <int> prix;
 vector <bool> proposition;
 vector <int> visite;

public:
    Acheteur(int prix, bool proposition)
    {
     prix ={};
     proposition= false;
     viste ={};
    };
 
    //Fonction d'ajout d'une nouvelle visite
    void visite ( int prix, bool proposition, int idbien ){
    visite.push_back(idbien);
    visite.push_back( proposition);
    visite.push_back(prix);
    };
 
    //fonction pour consulter toutes les visites
    tab ConsultVisite ()
    { 
     return visite;
    };
 
    // fonction proposition d'une nouvelle visite
    bool Proposition (int idbien, int prix)
    { int i;
     for ( i= 0, i< visite.size(), i++){
      if (i = idvisite){
       visite[i] = idvisite;
       proposition[i] = true;
       prix[i] = prix;
      }
     }
    };
 
    //destructeur 
    ~Acheteur ();
};
