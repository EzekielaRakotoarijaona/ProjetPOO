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
#include "agence.h"


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
  void ajouter_client_vendeur(Vendeur c);
  void ajouter_client_acheteur(Acheteur c);
  void supprimer_client_vendeur(std::string nom);
  void supprimer_client_acheteur(std::string nom);
  inline void ajouter_maison(Maison m){_maison.insert(std::make_pair(m.retourner_id(),m));};
  inline void ajouter_appartement(Appartement a){_appartement.insert(std::make_pair(a.retourner_id(),a));};
  inline void ajouter_terrain(Terrain t){_terrain.insert(std::make_pair(t.retourner_id(),t));};
  inline void ajouter_locaux(Locaux_pro l){_locauxpro.insert(std::make_pair(l.retourner_id(),l));};
  void afficher();
};

#endif
