#include <iostream>
#include "acheteur.h"
using namespace std;

Acheteur::Acheteur(string _nom, string _adresse, vector<int> _prix, vector<bool> _proposition, vector<int> _idbien): Client(_nom, _adresse){
  prix = _prix;
  proposition = _proposition;
  idbien = _idbien;
  cout << "acheteur cree" << endl;
  this->Client::afficher();
}

void Acheteur::visite(int _prix, bool _proposition, int _idbien){
  prix.push_back(_prix);
  idbien.push_back(_idbien);
  proposition.push_back(_proposition);
}

void Acheteur::afficher(){
  for(int i = 0 ; i < idbien.size() ; i++)
    cout << "id du bien : " << idbien[i] << endl;
  for(int i = 0 ; i < proposition.size() ; i++)
    cout << "proposition : " << proposition[i] << endl;
  for(int i = 0 ; i < prix.size() ; i++)
    cout << "prix : " << prix[i] << endl;
}

void Acheteur::proposer_visite(int _idbien, int _prix){
  for (int i = 0 ; i < idbien.size() ; i++)
    if (i == _idbien){
      idbien[i] = _idbien;
      proposition[i] = true;
      prix[i] = _prix;
    }
}
