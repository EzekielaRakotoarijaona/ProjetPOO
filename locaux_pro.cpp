#include <iostream>
#include "locaux_pro.h"
using namespace std;

Locaux_pro::Locaux_pro(){
  taille_vitrine = 0;
  piece_stockage = false;
}

Locaux_pro::Locaux_pro(int taille, bool stockage){
  taille_vitrine = taille;
  piece_stockage = stockage;
}

void Locaux_pro::afficher(){
  cout << "taille vitrine : " << taille_vitrine << endl << "piece_stockage : " << piece_stockage << endl;
}
