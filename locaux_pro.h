#include <iostream>

class Locaux_pro: public Biens{
protected:
  int taille_vitrine;
  bool piece_stockage;
public:
  inline Locaux_pro() {taille_vitrine = 0; piece_stockage = false;};
  inline Locaux_pro(int taille, bool stockage) {taille_vitrine = taille; piece_stockage = stockage;};
  inline int retourner_taille() {return taille_vitrine;};
  inline bool retourner_stockage() {return piece_stockage;};
  inline ~Locaux_pro() {};
};
