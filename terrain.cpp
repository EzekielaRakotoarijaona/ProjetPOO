#include <iostream>
#include "terrain.h"
using namespace std;

/* ------------------------------------------------------------------------------------------------------------------------- */

// ce constructeur va permettre de creer un objet terrain
Terrain::Terrain(int _prix, std::string _adresse, int _surface, std::string _reference, int _id_bien,bool _constructible):Biens(_prix,_adresse,_surface,_reference,_id_bien){
  constructible = _constructible;
  cout << "terrain cree" << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher totues les donnees d'un terrain
void Terrain::afficher(){
  cout << "constructible : " << constructible << endl;
  this->Biens::afficher();
  cout << endl;
}
