#include <iostream>
#include <vector>
#include "vendeur.h"
using namespace std;

/* ------------------------------------------------------------------------------------------------------------------------- */

// ce constructeur va permettre de creer un objet client vendeur
Vendeur::Vendeur(string nom, string adresse):Client(nom, adresse){
  cout << "vendeur cree" << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher les donnees du client vendeur
void Vendeur::afficher_vendeur(){
  this->Client::afficher();
  cout << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher les biens d'un client vendeur
void Vendeur::afficher_b(){
  for(int i = 0 ; i < tableau_bien.size() ; i++)
    cout << "id bien : " << tableau_bien[i] << endl;
  cout << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'ajouter des biens dans la liste des biens du client vendeur
void Vendeur::ajouter_bien(int id){
  tableau_bien.push_back(id);
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de retirer des biens de la liste des biens du client vendeur
void Vendeur::retirer_bien(int id){
  for (int i = 0 ; i < tableau_bien.size() ; i++)
    if (tableau_bien.at(i) == id){
      tableau_bien.erase(tableau_bien.begin() + i);
      cout << "bien retire" << endl;
    }
}
