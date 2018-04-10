#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "biens.h"

class Terrain: public Biens{
protected:
  bool constructible;
public:
  Terrain(int _prix, std::string _adresse, int _surface, int _reference, int _id_bien,bool _constructible): Biens(_prix,_adresse,_surface,_reference,_id_bien) {constructible = _constructible;};
  inline bool retourner_constructible() {return constructible;};
  void afficher();
  inline ~Terrain() {};
};

#endif
