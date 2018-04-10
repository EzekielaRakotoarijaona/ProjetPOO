#ifndef LOCAUX_PRO_H
#define LOCAUX_PRO_H

#include <iostream>
#include "biens.h"

class Locaux_pro: public Biens{
protected:
  int taille_vitrine;
  bool piece_stockage;
public:
  Locaux_pro(int _prix, std::string _adresse, int _surface, int _reference, int _id_bien,int taille, bool stockage);
  inline int retourner_taille() {return taille_vitrine;};
  inline bool retourner_stockage() {return piece_stockage;};
  void afficher();
  inline ~Locaux_pro() {};
};

#endif
