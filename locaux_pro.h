#ifndef LOCAUX_PRO_H
#define LOCAUX_PRO_H

#include <iostream>

class Locaux_pro: public Biens{
protected:
  int taille_vitrine;
  bool piece_stockage;
public:
  Locaux_pro() {taille_vitrine = 0; piece_stockage = false;};
  Locaux_pro(int taille, bool stockage);
  inline int retourner_taille() {return taille_vitrine;};
  inline bool retourner_stockage() {return piece_stockage;};
  void afficher();
  inline ~Locaux_pro() {};
};

#endif
