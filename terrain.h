#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "biens.h"

class Terrain: public Biens{
  //Attribut
protected:
  bool constructible;
public:
  //Méthodes
  Terrain(int _prix, std::string _adresse, int _surface, std::string _reference, int _id_bien, bool _constructible);//Constructeur
  inline bool retourner_constructible() {return constructible;};
  void afficher();//Méthode qui affiche le terrain
  inline ~Terrain() {};//Destructeur
};

#endif
