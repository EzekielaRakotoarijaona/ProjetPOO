#include <iostream>
#include "acheteur.h"
using namespace std;

//constructeur
Acheteur::Acheteur(string _nom, string _adresse): Client(_nom, _adresse){
  cout << "acheteur cree" << endl;
}

//Methode ajouter visite
void Acheteur::ajouter_visite(int _prix, bool _proposition, int _idbien){
  prix.push_back(_prix);
  idbien.push_back(_idbien);
  proposition.push_back(_proposition);
}

void Acheteur::supprimer_visite(int _idbien){
  int fait = 0;
  for (int i = 0 ; i < idbien.size() ; i++)
    if (idbien[i] == _idbien){
      this->idbien.erase(idbien.begin() + i);
      this->proposition.erase(proposition.begin() + i);
      this->prix.erase(prix.begin() + i);
      fait = 1;
      cout << "visite supprimee" << endl;
    }
  if (fait == 0)
    cout << "erreur, aucune visite pour le bien ayant l'id " << _idbien << endl;
}

//Methode Afficher nom acheteur
void Acheteur::afficher_acheteur(){
  this->Client::afficher();
}

//Methode afficher les visites
void Acheteur::afficher_visites(){
  for(int i = 0 ; i < idbien.size() ; i++){
    cout << "id du bien : " << idbien[i] << endl;
    cout << "proposition : " << proposition[i] << endl;
    cout << "prix : " << prix[i] << endl << endl;
  }
}
