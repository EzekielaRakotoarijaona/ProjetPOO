#include <iostream>
#include <vector>
#include "vendeur.h"
using namespace std;

Vendeur::Vendeur(string nom, string adresse):Client(nom, adresse){
  cout << "vendeur cree" << endl;
  this->Client::afficher();
}

void Vendeur::afficher(){
  for(int i = 0 ; i < tableau_bien.size() ; i++)
    cout << "id bien : " << tableau_bien[i] << endl;
}

void Vendeur::ajouter_bien(int id){
  tableau_bien.push_back(id);
}

bool Vendeur::retirer_bien(int id){
  for(int i = 0 ; i < tableau_bien.size() ; i++)
    if(tableau_bien.at(i) == id){
      tableau_bien.erase(tableau_bien.begin() + i);
      return true;
    }
    return false;
}
