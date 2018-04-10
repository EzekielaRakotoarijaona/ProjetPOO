#include <iostream>
#include "biens.h"
using namespace std;

Biens::Biens(){
  prix_bien = 0;
  adresse_bien = "\0";
  surface_bien = 0;
  ref_client_vendeur_bien = "\0";
  id_bien = 0;
}

Biens::Biens(int prix, string adresse, int surface, int reference, if id){
  prix_bien = prix;
  adresse_bien = adresse;
  surface_bien = surface;
  ref_client_vendeur_bien = reference;
  id_bien = id;
}

void virtual Biens::afficher(){
  cout << "prix : " << prix_bien << endl;
  cout << "adresse : " << adresse_bien << endl;
  cout << "surface : " << surface_bien << endl;
  cout << "reference client vendeur : " << ref_client_vendeur_bien << endl;
  cout << "id : " << id_bien << endl;
}
