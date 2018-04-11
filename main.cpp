#include <iostream>
using namespace std;
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "locaux_pro.h"
#include "acheteur.h"
#include "vendeur.h"
#include "agence.h"





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
