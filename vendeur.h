#ifndef VENDEUR_H
#define VENDEUR_H

#include <iostream>
#include <fstream>
#include <vector>
#include "client.h"

class Vendeur: public Client{
protected:
  // attributs
  std::vector<int> tableau_bien;

public:
  // methodes
  Vendeur(std::string nom, std::string adresse);
  void afficher_vendeur();
  void afficher_b();
  inline std::vector<int> retourner_tableauBien() {return tableau_bien;};
  void ajouter_bien(int id);
  void retirer_bien(int id);
  inline ~Vendeur() {};
};

#endif
