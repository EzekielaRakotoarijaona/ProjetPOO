#include <iostream>
#include <cstdlib>  //me faut cette ligne pour que ça marche sous windows, pardon
using namespace std;
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "locaux_pro.h"
#include "acheteur.h"
#include "vendeur.h"
#include "agence.h"


int create_id_maison(map <int,Maison> v){
    int id = rand()%100000;
    id += 1000000;
    while(v.find(id) != v.end()){
      int id = rand()%100000;
      id += 1000000;
    }
    return id;
}

int create_id_appartement(map <int,Appartement> v){
  int id = rand()%100000;
  id += 2000000;
  while(v.find(id) != v.end()){
    int id = rand()%100000;
    id += 2000000;
  }
  return id;
}

int create_id_locaux(map <int,Locaux_pro> v){
  int id = rand()%100000;
  id += 4000000;
  while(v.find(id) != v.end()){
    int id = rand()%100000;
    id += 4000000;
  }
  return id;
}

int create_id_terrain(map<int,Terrain> v){
  int id = rand()%100000;
  id += 3000000;
  while(v.find(id) != v.end()){
    int id = rand()%100000;
    id += 3000000;
  }
  return id;
}

int decode_id(int id){
  id = id/1000000;
  return id;
}

void ajout_client(Agence ag){
  int type_client = -1;
  string n;
  string ad;

  cout << "1 : acheteur\n2 : vendeur" << endl;
  cin >> type_client;
  cout << "nom du client : " << endl;
  cin >> n;
  cout << "adresse du client : " << endl;
  cin >> ad;

  if (type_client == 1){
    Acheteur a(n, ad);
    ag.ajouter_client_acheteur(a);
  }
  if (type_client == 2){
    Vendeur a(n, ad);
    ag.ajouter_client_vendeur(a);
  }
}

void consulter_visites(Agence ag){
  map <string, Acheteur> client_ach = ag.retourner_client_acheteur();
  map<string, Acheteur>::iterator it;
  for(it = client_ach.begin() ; it != client_ach.end() ; it++){
    it->second.afficher();
  }
}

void consulter_client(Agence ag){
  ag.afficher_clients();
}

void consulter_biens(Agence ag){
  int type = -1;
  cout << "quel type de bien ?" << endl;
  cout << "1 : appartement\n2 : maison\n3 : terrain\n4 : locaux pro" << endl;
  cin >> type;
  map <int, Appartement> app = ag.retourner_appartement();
  map <int, Appartement>::iterator it;
  map <int, Maison> mai = ag.retourner_maison();
  map <int, Maison>::iterator it2;
  map <int, Terrain> terr = ag.retourner_terrain();
  map <int, Terrain>::iterator it3;
  map <int, Locaux_pro> loc = ag.retourner_locauxpro();
  map <int, Locaux_pro>::iterator it4;

  switch(type){
    case 1:
      for(it = app.begin() ; it != app.end() ; it++)
        it->second.afficher();
      break;
    case 2:
      for(it2 = mai.begin() ; it2 != mai.end() ; it2++)
        it2->second.afficher();
      break;
    case 3:
      for(it3 = terr.begin() ; it3 != terr.end() ; it3++)
        it3->second.afficher();
      break;
    case 4:
      for(it4 = loc.begin() ; it4 != loc.end() ; it4++)
        it4->second.afficher();
      break;
  }
}

void gestion_menu(int &fin, int &commande){
  cout << "bienvenue sur votre logiciel de gestion" << endl << "que voulez-vous faire ?" << endl;
  cout << "\n1 : Consulter les visites et les biens disponibles" << "\n2 : gestion des clients" << "\n3 : quitter" << endl;
  cin >> commande;
}


int main(){
  Agence UnToitPourTous;
  int fin = 0;
  int commande = -1;
  int consult = -1;
  int action = -1;
  system("clear");
  while(fin == 0){
    gestion_menu(fin, commande);
    switch(commande){
      case 1:
        cout << "1 : consulter les visites\n2 : consulter les biens disponibles\n3 : consulter les clients" << endl;
        cin >> consult;
        if (consult == 1)
          consulter_visites(UnToitPourTous);
        if (consult == 2)
          consulter_biens(UnToitPourTous);
        if (consult == 3)
          consulter_client(UnToitPourTous);
        break;
      case 2:
        cout << "1 : ajouter un client\n2 : supprimer client\n3 : ajouter un bien\n4 : supprimer un bien" << endl;
        cin >> action;
        if (action == 1)
          ajout_client(UnToitPourTous);
        break;
        /*if (action == 2)
          suppr_client(UnToitPourTous);
        if (action == 3)
          ajout_bien(UnToitPourTous);
        if (action == 4)
          suppr_bien(UnToitPourTous);*/

      case 3:
        return 1;
    }
  }
  return 1;
}
