#include <iostream>
#include "acheteur.h"
using namespace std;

/* ------------------------------------------------------------------------------------------------------------------------- */

// ce constructeur va permettre de creer un objet acheteur
Acheteur::Acheteur(string _nom, string _adresse): Client(_nom, _adresse){
  cout << "acheteur cree" << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'ajouter des visites grace a l'ajout de donnees dans les 3 differents vecteurs
void Acheteur::ajouter_visite(int _prix, bool _proposition, int _idbien){
  prix.push_back(_prix);
  idbien.push_back(_idbien);
  proposition.push_back(_proposition);
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de supprimer les visites ayant pour id celui passe en parametre
bool Acheteur::supprimer_visite(int _idbien){
  for (int i = 0 ; i < idbien.size() ; i++)
    if (idbien[i] == _idbien){
      this->idbien.erase(idbien.begin() + i);
      this->proposition.erase(proposition.begin() + i);
      this->prix.erase(prix.begin() + i);
      cout << "visite supprimee" << endl;
      return true;
    }
  cout << "erreur, aucune visite pour le bien ayant l'id " << _idbien << endl;
  return false;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher le client acheteur
void Acheteur::afficher_acheteur(){
  this->Client::afficher();
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher la liste de toutes les visites d'un client acheteur
void Acheteur::afficher_visites(){
  for(int i = 0 ; i < idbien.size() ; i++){
    cout << "id du bien : " << idbien[i] << endl;
    cout << "proposition : " << proposition[i] << endl;
    cout << "prix : " << prix[i] << endl << endl;
  }
}
