#include <iostream>
#include <map>
#include "agence.h"
#include "vendeur.h"
#include "acheteur.h"
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "locaux_pro.h"
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
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

// constructeur agence
Agence::Agence(){
  clients_vendeurs.empty();
  clients_acheteurs.empty();
  _appartement.empty();
  _maison.empty();
  _terrain.empty();
  _locauxpro.empty();
  cout << "agence creee" << endl;
  //completer_client_acheteur();
}

// methode ajouter client vendeur
void Agence::ajouter_client_vendeur(Vendeur c){
  clients_vendeurs.insert(make_pair(c.retourner_nom(),c));
  cout<<"Client Ajoute"<<endl;
}

// methode ajouter client acheteur
void Agence::ajouter_client_acheteur(Acheteur c){
  clients_acheteurs.insert(make_pair(c.retourner_nom(),c));
  cout<<"Client Ajoute"<<endl;
}

//Methode supprimer client vendeur
void Agence::supprimer_client_vendeur(string nom){
  map<string,Vendeur>::iterator it;
  it = clients_vendeurs.find(nom);
  //Acceder a l'objet vendeur puis a son tableau de bien et supprimer tous les biens de ce vendeur
  clients_vendeurs.erase(it);
  cout<<"Client Supprime"<<endl;
}

// methode de suppression des clients acheteur
void Agence::supprimer_client_acheteur(string nom){
  map<string,Acheteur>::iterator it;
  it = clients_acheteurs.find(nom);
  clients_acheteurs.erase(it);
  cout<<"Client Supprime"<<endl;
}

// methode de suppression des appartements
void Agence::supprimer_appartement(int id){
  map<int,Appartement>::iterator it;
  it = _appartement.find(id);
  _appartement.erase(it);
  cout<<"Bien Supprime"<<endl;
}

// Methode de suppression des maison
void Agence::supprimer_maison(int id){
  map<int,Maison>::iterator it;
  it = _maison.find(id);
  _maison.erase(it);
  cout<<"Bien Supprime"<<endl;
}

 //Methode de suppression des terrains
void Agence::supprimer_terrain(int id){
  map<int,Terrain>::iterator it;
  it = _terrain.find(id);
  _terrain.erase(it);
  cout<<"Bien Supprime"<<endl;
}

 //methode de suppression des locaux
void Agence::supprimer_locaux(int id){
  map<int,Locaux_pro>::iterator it;
  it = _locauxpro.find(id);
  _locauxpro.erase(it);
  cout<<"Bien Supprime"<<endl;
}

void Agence::afficher_clients(){
  cout << "vide : " << clients_acheteurs.empty() << endl;
  for(map <string, Acheteur>::iterator it = clients_acheteurs.begin() ; it != clients_acheteurs.end() ; it++){
    it->second.afficher();
  }
  for(map <string, Vendeur>::iterator it2 = clients_vendeurs.begin() ; it2 != clients_vendeurs.end() ; it2++)
    it2->second.afficher();
}
