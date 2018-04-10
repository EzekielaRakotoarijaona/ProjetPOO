#include <iostream>
#include "acheteur.h"
using namespace std;

Acheteur::Acheteur(string _nom, string _adresse, vector<int> _prix, vector<bool> _proposition, vector<int> _visite): Client(_nom, _adresse){
  prix = _prix;
  proposition = _proposition;
  visite = _visite;
}

void Acheteur::visite(int prix, bool proposition, int idbien){
  visite.push_back(prix);
  visite.push_back(idbien);
  visite.push_back(proposition);
}

vector<int> Acheteur::ConsultVisite(){
  return visite;
}

bool Acheteur::Proposition(int idbien, int prix){
  int i;
  for (i= 0 ; i < visite.size() ; i++)
    if (i == idvisite){
      visite[i] = idvisite;
      proposition[i] = true;
      prix[i] = prix;
    }
}
