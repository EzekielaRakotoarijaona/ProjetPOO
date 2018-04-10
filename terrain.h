#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>

class Terrain: public Biens{
protected:
  bool constructible;
public:
  inline Terrain() {constructible = false;};
  inline Terrain(bool _constructible) {constructible = _constructible;};
  inline bool retourner_constructible() {return constructible;};
  inline void afficher() {cout << constructible << endl;};
  inline ~Terrain() {};
};

#endif
