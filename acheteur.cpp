#include <iostream>
#include "acheteur.h"
using namespace std;


Acheteur::Acheteur(string _nom, string _adresse): Client(_nom, _adresse){
  cout << "acheteur cree" << endl;
}

//Methode visite
void Acheteur::visite(int _prix, bool _proposition, int _idbien){
  prix.push_back(_prix);
  idbien.push_back(_idbien);
  proposition.push_back(_proposition);
}

//Methode Afficher
void Acheteur::afficher_acheteur(){
  this->Client::afficher();
}

void Acheteur::afficher_visites(){
  for(int i = 0 ; i < idbien.size() ; i++){
    cout << "id du bien : " << idbien[i] << endl;
    cout << "proposition : " << proposition[i] << endl;
    cout << "prix : " << prix[i] << endl;
  }
}

//Methode Proposer visite
void Acheteur::proposer_visite(int _idbien, int _prix){
  for (int i = 0 ; i < idbien.size() ; i++)
    if (i == _idbien){
      idbien[i] = _idbien;
      proposition[i] = true;
      prix[i] = _prix;
    }
}
