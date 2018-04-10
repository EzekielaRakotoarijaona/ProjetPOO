#include <iostream>
#include "locaux_pro.h"
using namespace std;

Locaux_pro::Locaux_pro(){
  taille_vitrine = 0;
  piece_stockage = false;
  cout << "locaux crees" << endl;
}

Locaux_pro::Locaux_pro(int taille, bool stockage){
  taille_vitrine = taille;
  piece_stockage = stockage;
  cout << "locaux crees" << endl;
}

void Locaux_pro::afficher(){
  cout << "taille vitrine : " << taille_vitrine << endl << "piece_stockage : " << piece_stockage << endl;
}
