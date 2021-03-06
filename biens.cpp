#include <iostream>
#include "biens.h"
using namespace std;

/* ------------------------------------------------------------------------------------------------------------------------- */

// ce constructeur surcharge va permettre de creer un bien selon differentes donnees passees en parametre
Biens::Biens(int prix, string adresse, int surface, string reference, int id){
  prix_bien = prix;
  adresse_bien = adresse;
  surface_bien = surface;
  ref_client_vendeur_bien = reference;
  id_bien = id;
  cout << "bien cree" << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher toutes les donnees d'un bien
void Biens::afficher(){
  cout << "prix : " << prix_bien << endl;
  cout << "adresse : " << adresse_bien << endl;
  cout << "surface : " << surface_bien << endl;
  cout << "reference client vendeur : " << ref_client_vendeur_bien << endl;
  cout << "id : " << id_bien << endl << endl;
}
