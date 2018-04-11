#include <iostream>
using namespace std;
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "locaux_pro.h"
#include "acheteur.h"
#include "vendeur.h"
#include "agence.h"


int create_id_maison(vector<int,Maison> v)
{
    int id = rand()%100000;
    id += 1000000
    while(v.find(id) != v.end())
    {
      int id = rand()%100000;
      id += 1000000;
    }
    return id;
}

int create_id_appartement(vector<int,Appartement> v)
{
  int id = rand()%100000;
  id += 2000000
  while(v.find(id) != v.end())
  {
    int id = rand()%100000;
    id += 2000000;
  }
  return id;
}

int create_id_locaux(vector<int,Locaux_pro> v)
{
  int id = rand()%100000;
  id += 4000000
  while(v.find(id) != v.end())
  {
    int id = rand()%100000;
    id += 4000000;
  }
  return id;
}

int create_id_terrain(vector<int,Terrain> v)
{
  int id = rand()%100000;
  id += 3000000
  while(v.find(id) != v.end())
  {
    int id = rand()%100000;
    id += 3000000;
  }
  return id;
}

int decode_id(int id)
{
  id = id/1000000;
  return id;
}


void gestion_menu(int &fin, int &commande){
  system("clear");
  cout << "bienvenue sur votre logiciel de gestion" << endl << "que voulez-vous faire ?" << endl;
  cout << "\n1 : Consulter les visites et les biens disponibles" << "\n2 : gestion des clients" << "\n3 : quitter" << endl;
  cin >> commande;
}


int main(){
  Agence UnToitPourTous;
  int fin = 0;
  int commande = -1;
  system("clear");
  while(fin == 0){
    gestion_menu(fin, commande);
    switch(commande){
      /*case 1:
        int consult = 0;
        cout << "1 : consulter les visites\n2 : consulter les biens disponibles" << endl;
        cin >> consult;
        if (consult == 1)
          //consulter_visites(UnToitPourTous);
        if (consult == 2)
          //consulter_biens(unToitPourTous);
        break;
      case 2:
        break;*/
      case 3:
        return 1;
    }
  }
  return 1;
}
