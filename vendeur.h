#ifndef VENDEUR_H
#define VENDEUR_H

#include <iostream>
#include <vector>
#include "client.h"

class Vendeur: public Client{
protected:
  //Attributs
  std::vector<int> tableau_bien;
public:
  //Méthodes
  Vendeur(std::string nom, std::string adresse);
  void afficher();//Méthode qui affiche les infos vendeur 
  inline std::vector<int> retourner_tableauBien() {return tableau_bien;};
  void ajouter_bien(int id);
  bool retirer_bien(int id);
  inline ~Vendeur() {};//Destructeur
};

#endif
