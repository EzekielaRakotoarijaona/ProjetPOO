#ifndef VENDEUR_H
#define VENDEUR_H

#include <iostream>
#include <vector>
#include "client.h"

class Vendeur: class Client{
protected:
  std::vector<int> tableau_bien;
public:
  inline Vendeur(string nom, string adresse, vector<int> bien):Client(nom, adresse) {tableau_bien = bien;};
  inline void afficher() {for(int i = 0 ; i < tableau_bien.size() ; i++)  cout << tableau_bien[i] << endl;};
  inline std::vector<int> retourner_tableauBien() {return tableau_bien;};
  inline void ajouter_bien(int id) {    tableau_bien.push_back(id);  };
  inline bool retirer_bien(int id) {
    for(vector<int>::iterator it = tableau_bien.begin() ; it < tableau_bien.end() ; it++)
      if(tableau_bien).at(it) == id){        tableau_bien.erase(it);        return true;      }    return false; }
  inline ~Vendeur() {};
};

#endif
