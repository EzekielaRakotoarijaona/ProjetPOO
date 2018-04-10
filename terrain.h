#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>

class Terrain: public Biens{
protected:
  bool constructible;
public:
  Terrain() {constructible = false;};
  Terrain(bool _constructible) {constructible = _constructible;};
  inline bool retourner_constructible() {return constructible;};
  void afficher();
  inline ~Terrain() {};
};

#endif
