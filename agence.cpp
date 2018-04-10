#include <iostream>
#include <map>
#include "vendeur.h"
#include "acheteur.h"
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "locaux_Pro.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;


void completer_client_acheteur(){
  FILE* fichier = NULL;
  fichier = fopen("acheteurs.txt", "r");
  
}

Agence::Agence(){
  clients_vendeurs = {};
  clients_acheteurs = {};
  _appartement = {};
  _maison = {};
  _terrain = {};
  _locauxpro = {};
  completer_client_acheteur();
}
