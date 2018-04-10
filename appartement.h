#ifndef APPARTEMENT_H
#define APPARTEMENT_H

#include <iostream>
#include "biens.h"


class Appartement: public Biens{
protected:
  int nombre_de_piece_appartement;
  int etage;
  bool garage;
  bool cave;
  bool balcon;
  int nombre_appartement_immeuble;
public:
  Appartement(int _prix, std::string _adresse, int _surface, std::string _reference, int _id_bien,int _nb_pieces, int _etage, bool _garage, bool _cave, bool _balcon, int _nb_appart_imm);
  int retourner_nombrePieceAppartement();
  inline int retourner_etage() {return etage;};
  inline bool retourner_garage() {return garage;};
  inline bool retourner_cave() {return cave;};
  inline bool retourner_balcon() {return balcon;};
  inline int retourner_nbAppartImm() {return nombre_appartement_immeuble;};
  void afficher();
  inline ~Appartement() {};
};

#endif
