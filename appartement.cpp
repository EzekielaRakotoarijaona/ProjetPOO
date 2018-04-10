#include <iostream>
#include "appartement.h"
using namespace std;

Appartement::Appartement(){
  nombre_de_piece_appartement = 0;
  etage = 0;
  garage = false;
  cave = false;
  balcon = false;
  nombre_appartement_immeuble = 0;
}

Appartement::Appartement(int _nb_pieces, int _etage, bool _garage, bool _cave, bool _balcon, int _nb_appart_imm){
  nombre_de_piece_appartement = _nb_pieces;
  etage = _etage;
  garage = _garage;
  cave = _cave;
  balcon = _balcon;
  nombre_appartement_immeuble = _nb_appart_imm;
}

int Appartement::retourner_nombrePieceAppartement(){
  return nombre_de_piece_appartement;
}


void Appartement::afficher(){
  cout << "nombre de piece appartement : " << nombre_de_piece_appartement << endl;
  cout << "etage : " << etage << endl;
  cout << "garage : " << garage << endl;
  cout << "cave : " << cave << endl;
  cout << "balcon : " << balcon << endl;
  cout << "nombre appartement immeuble : " << nombre_appartement_immeuble << endl;
}