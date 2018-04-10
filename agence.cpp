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

#define TAILLE_MAX 4096

/*
void completer_client_acheteur(std::map<string, Acheteur> table_acheteur;){
  FILE* fichier = NULL;                           // on créé un pointeur sur un fichier, initialisé à null
  fichier = fopen("acheteurs.txt", "r");          // on ouvre le fichier
  string nom = "";                                // on créé les différents attributs à récupérer dans le dossier
  string adresse = "";
  vector<int> id = {};
  vector<bool> proposition = {};
  vector<int> prix = {};
  while(fgets == EOF){                            // on créé la boucle pour récupérer chaque objet, sachant qu'un objet = 3 lignes
    char chaine[TAILLE_MAX] = " ";
    fgets(chaine, TAILLE_MAX, fichier);
    nom = chaine;                                 // 1ère donnée de l'objet

    fgets(chaine, TAILLE_MAX, fichier);
    adresse = chaine;                             // 2e donnée de l'objet

    fgets(chaine, TAILLE_MAX, fichier);           // pour la 3e donnée, on va récupérer 3 éléments : l'id, la proposition et le prix
    char* token = strtok(chaine, " ");            // token est une chaîne de char qui va pointer sur le débu de la chaîne, jusqu'à trouver un espace

    while(token != NULL){                         // on va interpréter token

      id.push_back(strtol(token, NULL, 10));      // la première valeur est l'id, on le rajoute dans le vector

      token = strtok(NULL, " ");                  // on avance le token pour qu'il prenne la prochaine chaîne de char
      proposition.push_back(strtol(token, NULL, 10));

      token = strtok(NULL, " ");                  // on avance le token pour qu'il prenne la prochaine chaîne de char
      prix.push_back(strtol(token, NULL, 10));

      token = strtok(NULL, " ");                  // on avance le token pour qu'il prenne la prochaine chaîne de char
    }
    Acheteur a(nom, adresse, id, proposition, prix);
    table_acheteur.push_back(a);
    id.clear();                                   // on vide les 3 vecteurs car on va les utiliser pour le prochain objet
    proposition.clear();
    prix.clear();
  }
  fclose(fichier);
}
*/

Agence::Agence(){
  clients_vendeurs = {};
  clients_acheteurs = {};
  _appartement = {};
  _maison = {};
  _terrain = {};
  _locauxpro = {};
  cout << "agence creee" << endl;
  //completer_client_acheteur();
}
