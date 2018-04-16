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
  // attributs
  std::map <std::string, Vendeur> clients_vendeurs;
  std::map <std::string, Acheteur> clients_acheteurs;
  std::map <int, Appartement> _appartement;
  std::map <int, Maison> _maison;
  std::map <int, Terrain> _terrain;
  std::map <int, Locaux_pro> _locauxpro;

public:
  // methodes
  Agence();
  void creer_visite(std::string nom, int idbien, bool proposition, int prix);
  void acheter_bien(int idbien, std::string &nom, int &prix);
  void afficher_biens_vendeurs();
  void ajouter_client_vendeur(Vendeur c);
  void ajouter_client_acheteur(Acheteur c);
  void supprimer_client_vendeur(std::string nom);
  void supprimer_client_acheteur(std::string nom);
  void ajouter_maison(Maison m);
  void ajouter_appartement(Appartement a);
  void ajouter_terrain(Terrain t);
  void ajouter_locaux(Locaux_pro l);
  void supprimer_appartement(int id);
  void supprimer_maison(int id);
  void supprimer_terrain(int id);
  void supprimer_locaux(int id);
  void afficher_clients();
  void afficher_biens();
  inline std::map <std::string, Vendeur> retourner_client_vendeur() {return clients_vendeurs;};
  inline std::map <std::string, Acheteur> retourner_client_acheteur() {return clients_acheteurs;};
  inline std::map <int, Appartement> retourner_appartement() {return _appartement;};
  inline std::map <int, Maison> retourner_maison() {return _maison;};
  inline std::map <int, Terrain> retourner_terrain() {return _terrain;};
  inline std::map <int, Locaux_pro> retourner_locauxpro() {return _locauxpro;};
  bool existe_ref_client(std::string ref_client);
  bool existe_bien(int bien, int idbien, std::string &nom);
  void rechercher_bien_selon_prix(int operateur, int prix, int bien);
  void rechercher_bien_selon_option(bool jardin, bool piscine, bool garage, bool cave, bool balcon, bool constructible, bool piece_stockage);
  ~Agence();
};

#endif
