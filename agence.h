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
  // Attributs
protected:
  std::map <std::string, Vendeur> clients_vendeurs;
  std::map <std::string, Acheteur> clients_acheteurs;
  std::map <int, Appartement> _appartement;
  std::map <int, Maison> _maison;
  std::map <int, Terrain> _terrain;
  std::map <int, Locaux_pro> _locauxpro;
  // Méthodes
public:
  Agence();
  void ajouter_client_vendeur(Vendeur c);//Méthode ajouter client vendeur
  void ajouter_client_acheteur(Acheteur c);//Méthode ajouter client acheteur
  void supprimer_client_vendeur(std::string nom);//Méthode supprimer client vendeur
  void supprimer_client_acheteur(std::string nom);//Méthode supprimer client acheteur
  inline void ajouter_maison(Maison m){_maison.insert(std::make_pair(m.retourner_id(),m));};
  inline void ajouter_appartement(Appartement a){_appartement.insert(std::make_pair(a.retourner_id(),a));};
  inline void ajouter_terrain(Terrain t){_terrain.insert(std::make_pair(t.retourner_id(),t));};
  inline void ajouter_locaux(Locaux_pro l){_locauxpro.insert(std::make_pair(l.retourner_id(),l));};
  void supprimer_appartement(int id);//Méthode supprimer appartements
  void supprimer_maison(int id);//Méthode supprimer maison
  void supprimer_terrain(int id);//Méthode supprimer terrain
  void supprimer_locaux(int id);//Méthode supprimer locaux professionnels
  void afficher_clients();//Méthode afficher clients
  void afficher_biens();//Méthode afficher biens 
  inline std::map <std::string, Vendeur> retourner_client_vendeur() {return clients_vendeurs;};
  inline std::map <std::string, Acheteur> retourner_client_acheteur() {return clients_acheteurs;};
  inline std::map <int, Appartement> retourner_appartement() {return _appartement;};
  inline std::map <int, Maison> retourner_maison() {return _maison;};
  inline std::map <int, Terrain> retourner_terrain() {return _terrain;};
  inline std::map <int, Locaux_pro> retourner_locauxpro() {return _locauxpro;};

};

#endif
