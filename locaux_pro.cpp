#include <iostream>
#include "locaux_pro.h"
using namespace std;

//Fonction constructeur avec spécifications
Locaux_pro::Locaux_pro(int _prix, std::string _adresse, int _surface, string _reference, int _id_bien,int taille, bool stockage):Biens(_prix,_adresse,_surface,_reference,_id_bien){
  taille_vitrine = taille;
  piece_stockage = stockage;
  cout << "locaux crees" << endl;
}
//Fonction d'affichage
void Locaux_pro::afficher(){
  cout << "taille vitrine : " << taille_vitrine << endl << "piece_stockage : " << piece_stockage << endl;
  this->Biens::afficher();
}
