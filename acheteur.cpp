#include <iostream>
#include "acheteur.h"
using namespace std;


Acheteur::Acheteur(string _nom, string _adresse): Client(_nom, _adresse){
  cout << "acheteur cree" << endl;
}

//Methode visite
void Acheteur::ajouter_visite(int _prix, bool _proposition, int _idbien){
  cout << "la taille est : " << prix.size() << endl;
  prix.push_back(_prix);
  idbien.push_back(_idbien);
  proposition.push_back(_proposition);
  cout << "la taille est : " << prix.size() << endl;
}

//Methode Afficher
void Acheteur::afficher_acheteur(){
  this->Client::afficher();
}

void Acheteur::afficher_visites(){
  cout << "vide :" <<idbien.empty() << endl << endl << endl;
  for(int i = 0 ; i < idbien.size() ; i++){
    cout << "id du bien : " << idbien[i] << endl;
    cout << "proposition : " << proposition[i] << endl;
    cout << "prix : " << prix[i] << endl << endl;
  }
}
