#ifndef AGENCE_H
#define AGENCE_H

#include <iostream>
#include <map>
#include "vendeur.h"
#include "acheteur.h"
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "locaux_pro.h"


class Agence{
protected:
  std::map <std::string, Vendeur> clients_vendeurs;
  std::map <std::string, Acheteur> clients_acheteurs;
  std::map <int, Appartement> _appartement;
  std::map <int, Maison> _maison;
  std::map <int, Terrain> _terrain;
  std::map <int, Locaux_pro> _locauxpro;
public:
  Agence();
};

#endif
