#ifndef ACHETEUR_H
#define ACHETEUR_H
#include <iostream>
#include <vector>
#include "client.h"


class Acheteur: public Client{
protected:
  // attributs
  std::vector <int> prix;
  std::vector <bool> proposition;
  std::vector <int> idbien;

public:
  // methodes
  Acheteur(std::string _nom, std::string _adresse);
  void ajouter_visite(int _prix, bool _proposition, int _idbien);
  void supprimer_visite(int _idbien, bool &suppression, std::string &nom, int &depense, bool forcage_suppression);
  inline std::vector <int> retourner_prix() { return prix; };
  inline std::vector <bool> retourner_proposition() { return proposition; };
  inline std::vector <int> retourner_idbien() { return idbien; };
  void afficher_acheteur();
  void afficher_visites();
  inline ~Acheteur () {};
};

#endif
