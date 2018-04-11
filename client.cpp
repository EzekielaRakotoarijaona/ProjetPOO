#include <iostream>
#include "client.h"
using namespace std;

//Constructeur sans spécifications 
Client::Client(){
  nom = "\0";
  adresse = "\0";
  cout << "client cree" << endl;
}

// constructeur avec spécifications
Client::Client(string n, string ad){
  nom = n;
  adresse = ad;
  cout << "client cree" << endl;
}

//Methode d'affichage
void Client::afficher(){
  cout << "nom client : " << nom << endl << "adresse client : " << adresse << endl;
}
