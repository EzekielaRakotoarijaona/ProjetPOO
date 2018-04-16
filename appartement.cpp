#include <iostream>
#include "appartement.h"
using namespace std;

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de construire un objet appartement
Appartement::Appartement(int _prix, std::string _adresse, int _surface, string _reference, int _id_bien,int _nb_pieces, int _etage, bool _garage, bool _cave, bool _balcon, int _nb_appart_imm):Biens(_prix,_adresse,_surface,_reference,_id_bien){
  nombre_de_piece_appartement = _nb_pieces;
  etage = _etage;
  garage = _garage;
  cave = _cave;
  balcon = _balcon;
  nombre_appartement_immeuble = _nb_appart_imm;
  cout << "appartement cree" << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de recuperer la valeur du nombre de piece dans l'appartement
int Appartement::retourner_nombrePieceAppartement(){
  return nombre_de_piece_appartement;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher toutes les donnees d'un appartement
void Appartement::afficher(){
  cout << "nombre de piece appartement : " << nombre_de_piece_appartement << endl;
  cout << "etage : " << etage << endl;
  cout << "garage : " << garage << endl;
  cout << "cave : " << cave << endl;
  cout << "balcon : " << balcon << endl;
  cout << "nombre appartement immeuble : " << nombre_appartement_immeuble << endl;
  this->Biens::afficher();
}
