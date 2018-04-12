#include <iostream>
#include <vector>
#include "vendeur.h"
using namespace std;

Vendeur::Vendeur(string nom, string adresse):Client(nom, adresse){ //Constructeur
  cout << "vendeur cree" << endl;

}


void Vendeur::afficher_vendeur(){
  this->Client::afficher();
  cout << endl;
}

void Vendeur::afficher_b(){
  for(int i = 0 ; i < tableau_bien.size() ; i++)
    cout << "id bien : " << tableau_bien[i] << endl;
  cout << endl;
}

void Vendeur::ajouter_bien(int id){ //Méthode qui ajoute un bien au compte du vendeur
  tableau_bien.push_back(id);
}

bool Vendeur::retirer_bien(int id){ //Méthode qui
  for(int i = 0 ; i < tableau_bien.size() ; i++)
    if(tableau_bien.at(i) == id){
      tableau_bien.erase(tableau_bien.begin() + i);
      return true;
    }
    return false;
 // Faut it pas ajouter la methode Modifier bien ?
}
