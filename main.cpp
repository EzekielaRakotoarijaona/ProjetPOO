#include <iostream>
using namespace std;
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "locaux_pro.h"
#include "acheteur.h"
#include "vendeur.h"
#include "agence.h"

int main(){
  Agence a;

  vector<int>prix;
  vector<int>idbien;
  vector<bool>proposition;
  prix.push_back(0);
  idbien.push_back(0);
  proposition.push_back(0);
  Acheteur ach("maxime", "allee_fromage", prix, proposition, idbien);
  ach.afficher();
  a.ajouter_client_acheteur(ach);
  a.supprimer_client_acheteur(ach.retourner_nom());

  Maison mais(1500, "rue fromage", 1500, "dupont", 26, 5, true, false, true);
  mais.afficher();

  Appartement app(15000, "rue fromage", 1200, "roger", 46, 8, 2, true, false, true, 66);
  app.afficher();

  Terrain terr(1600000, "rue fromage", 800, "sylvie", 61, true);
  terr.afficher();


  return 1;
}
