#include <iostream>
#include "client.h"
using namespace std;

/* ------------------------------------------------------------------------------------------------------------------------- */

// ce constructeur surcharge va permettre de creer un client selon les donnees passees en parametre
Client::Client(string n, string ad){
  nom = n;
  adresse = ad;
  cout << "client cree" << endl;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre d'afficher les donnees du client
void Client::afficher(){
  cout << "nom client : " << nom << endl << "adresse client : " << adresse << endl << endl;
}
