#include <iostream>
#include "maison.h"
using namespace std;

/* ------------------------------------------------------------------------------------------------------------------------- */

// ce constructeur va permettre de creer un objet maison
Maison::Maison(int prix, string adresse, int surface, string ref_client, int _id_bien, int _nombre_pieces, bool _garage, bool _jardin, bool _piscine):Biens(prix, adresse, surface, ref_client, _id_bien){
  nombre_pieces = _nombre_pieces;
  garage = _garage;
  jardin = _jardin;
  piscine = _piscine;
  cout << "maison creee" << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher toutes les donnees de la maison
void Maison::afficher(){
  cout << "nombre piece : " << nombre_pieces << endl;
  cout << "garage : " << garage << endl;
  cout << "jardin : " << jardin << endl;
  cout << "piscine : " << piscine << endl;
  this->Biens::afficher();
  cout << endl;
}
