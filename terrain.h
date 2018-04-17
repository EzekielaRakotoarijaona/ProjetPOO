#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "biens.h"

class Terrain: public Biens{
protected:
  // attributs
  bool constructible;

public:
  // methodes
  Terrain(int _prix, std::string _adresse, int _surface, std::string _reference, int _id_bien, bool _constructible);
  inline bool retourner_constructible() { return constructible; };
  void afficher();
  inline ~Terrain() {};
};

#endif
