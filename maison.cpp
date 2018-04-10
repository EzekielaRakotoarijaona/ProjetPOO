#include <iostream>
#include "maison.h"
using namespace std;

Maison::Maison(int prix, string adresse, int surface, string ref_client, int _id_bien,int _nombre_pieces, bool _garage, bool _jardin, bool _piscine):Biens(prix, adresse, surface, ref_client, _id_bien){
  nombre_pieces = _nombre_pieces;
  garage = _garage;
  jardin = _jardin;
  piscine = _piscine;
}

void Maison::afficher(){
  cout << "nombre piece : " << nombre_pieces << endl;
  cout << "garage : " << garage << endl;
  cout << "jardin : " << jardin << endl;
  cout << "piscine : " << piscine << endl;
}