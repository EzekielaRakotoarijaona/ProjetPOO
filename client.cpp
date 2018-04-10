#include <iostream>
#include "client.h"
using namespace std;

Client::Client(){
  nom = "\0";
  adresse = "\0";
  cout << "client cree" << endl;
}

Client::Client(string n, string ad){
  nom = n;
  adresse = ad;
  cout << "client cree" << endl;
}

void Client::afficher(){
  cout << "nom client : " << nom << endl << "adresse client : " << adresse << endl;
}
