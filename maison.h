#ifndef MAISON_H
#define MAISON_H

#include <iostream>
#include "biens.h"

class Maison: public Biens{
protected:
  // attributs
  int nombre_pieces;
  bool garage;
  bool jardin;
  bool piscine;
  
public:
  // methodes
  Maison(int prix, std::string adresse, int surface, std::string ref_client, int _id_bien,int _nombre_pieces, bool _garage, bool _jardin, bool _piscine);
  inline int retourner_nombre_pieces(){return nombre_pieces;};
  inline bool retourner_jardin(){ return jardin;};
  inline bool retourner_garage(){return  garage;};
  inline bool retourner_piscine(){return piscine;};
  void afficher();
  inline ~Maison() {};
};

#endif
