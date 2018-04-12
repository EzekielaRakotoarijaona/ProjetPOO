#include <iostream>
#include "terrain.h"
using namespace std;

Terrain::Terrain(int _prix, std::string _adresse, int _surface, std::string _reference, int _id_bien,bool _constructible):Biens(_prix,_adresse,_surface,_reference,_id_bien){
  constructible = _constructible;
  cout << "terrain cree" << endl;
}

void Terrain::afficher(){ //Méthode qui affiche les infos sur le terrain
  cout << "constructible : " << constructible << endl;
  this->Biens::afficher();
  cout << endl;
}
