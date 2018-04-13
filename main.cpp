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




void gestion_menu(int &fin, int &commande){
  cout << "\n1 : Consulter les visites et les biens disponibles" << "\n2 : gestion des clients et des biens" << "\n3 : quitter" << endl;
  cin >> commande;
}


int main(){
  // INITIALISATION DES DONNEES
  Agence UnToitPourTous;
  int fin = 0;
  int commande = -1;
  int consult = -1;
  int action = -1;
  system("clear");
  cout << "bienvenue sur votre logiciel de gestion" << endl;

  // BOUCLE, VA PERMETTRE DE FAIRE TOURNER LE PROGRAMME
  while(fin == 0){
    gestion_menu(fin, commande);
    switch(commande){

      // CONSULTATION DE DONNEES
      case 1:
        cout << "1 : consulter les visites\n2 : consulter les biens disponibles\n3 : consulter les clients\n4 : consulter les biens d'un client\n5 : rechercher" << endl;
        cin >> consult;

        // ce cas va traiter l'affichage de toutes les visites
        if (consult == 1){
          map <string, Acheteur> client_ach = UnToitPourTous.retourner_client_acheteur();
          map<string, Acheteur>::iterator it;
          for(it = client_ach.begin() ; it != client_ach.end() ; it++){
            it->second.afficher_visites();
          }
        }

        // ce cas va traiter l'affichage de tous les biens
        if (consult == 2)
          UnToitPourTous.afficher_biens();

        // ce cas va traiter l'affichage des clients vendeurs et acheteurs
        if (consult == 3)
          UnToitPourTous.afficher_clients();

        if (consult == 4)
          UnToitPourTous.afficher_biens_vendeurs();

        if (consult == 5){
          int rech = -1;
          cout << "1 : rechercher un bien selon son prix" << endl;
          cin >> rech;
          if (rech == 1){
            int prix = -1;
            int operateur = -1;
            int type_de_bien = -1;
            cout << "quel type de bien " << endl;
            cout << "1 : maison\n2 : appartement\n3 : terrain\n4 : locaux pro" << endl;     cin >> type_de_bien;
            cout << "1 : inferieur a\n2 : superieur a" << endl;                             cin >> operateur;
            cout << "quel prix : " << endl;                                                 cin >> prix;
            UnToitPourTous.rechercher_bien_selon_prix(operateur, prix, type_de_bien);
          }
        }
        break;

      // GESTION DES CLIENTS, DES BIENS ET DES VISITES
      case 2:
        cout << "1 : ajouter un client\n2 : supprimer client\n3 : ajouter un bien\n4 : supprimer un bien\n5 : ajouter une visite" << endl;
        cin >> action;

        // ce cas va traiter l'ajout d'un client dans la map associée de la classe agence
        if (action == 1){
          int type_client = -1;
          string nom_du_client;
          string adresse_du_client;

          cout << "1 : acheteur\n2 : vendeur" << endl;     cin >> type_client;
          cout << "nom du client : " << endl;              cin >> nom_du_client;
          cout << "adresse du client : " << endl;          cin >> adresse_du_client;

          if (type_client == 1){
            Acheteur acheteur_a_ajouter(nom_du_client, adresse_du_client);
            UnToitPourTous.ajouter_client_acheteur(acheteur_a_ajouter);
          }
          if (type_client == 2){
            Vendeur vendeur_a_ajouter(nom_du_client, adresse_du_client);
            UnToitPourTous.ajouter_client_vendeur(vendeur_a_ajouter);
          }
        }

        // ce cas va traiter la suppression des clients en fonction de leur nom
        if (action == 2){
          int type_client = -1;
          string suppression;
          cout << "1 : acheteur\n2 : vendeur" << endl;          cin >> type_client;
          cout << "nom du client a supprimer : " << endl;       cin >> suppression;

          if (type_client == 1)
            UnToitPourTous.supprimer_client_acheteur(suppression);

          if (type_client == 2)
            UnToitPourTous.supprimer_client_vendeur(suppression);

        }

        // ce cas va traiter l'ajout de differents biens
        if (action == 3){
          int type_bien = -1;
          int prix;
          string adresse;
          int surface;
          string ref_client;
          int id_bien;
          cout << "1 : maison\n2 : appartement\n3 : terrain\n4 : locaux pro" << endl;  cin >> type_bien;
          cout << "prix du bien : " << endl;                                           cin >> prix;
          cout << "adresse du bien : " << endl;                                        cin >> adresse;
          cout << "surface du bien : " << endl;                                        cin >> surface;
          cout << "reference du client : " << endl;                                    cin >> ref_client;


          if (type_bien == 1){
            int nombre_pieces;
            bool garage;
            bool jardin;
            bool piscine;
            id_bien = create_id_maison(UnToitPourTous.retourner_maison());
            cout << "nombre de pieces : " << endl;                         cin >> nombre_pieces;
            cout << "presence d'un garage (1 ou 0) : " << endl;            cin >> garage;
            cout << "presence d'un jardin (1 ou 0) : " << endl;            cin >> jardin;
            cout << "presence d'une piscine (1 ou 0) : " << endl;          cin >> piscine;
            Maison mai(prix, adresse, surface, ref_client, id_bien, nombre_pieces, garage, jardin, piscine);
            UnToitPourTous.ajouter_maison(mai);
          }

          if (type_bien == 2){
            int nombre_de_piece_appartement;
            int etage;
            bool garage;
            bool cave;
            bool balcon;
            int nombre_appartement_immeuble;
            id_bien = create_id_appartement(UnToitPourTous.retourner_appartement());
            cout << "nombre de pieces : " << endl;                         cin >> nombre_de_piece_appartement;
            cout << "nombre d'etage : " << endl;                           cin >> etage;
            cout << "presence d'un garage (1 ou 0) : " << endl;            cin >> garage;
            cout << "presence d'une cave (1 ou 0) : " << endl;             cin >> cave;
            cout << "presence d'un balcon (1 ou 0) : " << endl;            cin >> balcon;
            cout << "nombre d'appartement dans l'immeuble : " << endl;     cin >> nombre_appartement_immeuble;
            Appartement app(prix, adresse, surface, ref_client, id_bien, nombre_de_piece_appartement, etage, garage, cave, balcon, nombre_appartement_immeuble);
            UnToitPourTous.ajouter_appartement(app);
          }


          if (type_bien == 3){
            bool constructible;
            id_bien = create_id_terrain(UnToitPourTous.retourner_terrain());
            cout << "le terrain est constructible (1 ou 0) : " << endl;     cin >> constructible;
            Terrain terr(prix, adresse, surface, ref_client, id_bien, constructible);
            UnToitPourTous.ajouter_terrain(terr);
          }

          if (type_bien == 4){
            int taille_vitrine;
            bool piece_stockage;
            id_bien = create_id_locaux(UnToitPourTous.retourner_locauxpro());
            cout << "taille de la vitrine : " << endl;                        cin >> taille_vitrine;
            cout << "presence d'une piece de stockage (1 ou 0) : " << endl;   cin >> piece_stockage;
            Locaux_pro loc(prix, adresse, surface, ref_client, id_bien, taille_vitrine, piece_stockage);
            UnToitPourTous.ajouter_locaux(loc);
          }
        }

        // ce cas va traiter la suppression d'un bien selon son identifiant
        if (action == 4){
          int type_bien = -1;
          int suppression;
          cout << "1 : maison\n2 : appartement\n3 : terrain\n4 : locaux pro" << endl;  cin >> type_bien;
          cout << "id du bien a supprimer : " << endl;                                 cin >> suppression;

          if (type_bien == 1)
            UnToitPourTous.supprimer_maison(suppression);

          if (type_bien == 2)
            UnToitPourTous.supprimer_appartement(suppression);

          if (type_bien == 3)
            UnToitPourTous.supprimer_terrain(suppression);

          if (type_bien == 4)
            UnToitPourTous.supprimer_locaux(suppression);
        }

        // ce cas va permettre d'ajouter des visites
        if (action == 5){
          std::map <std::string, Acheteur> clients_acheteurs = UnToitPourTous.retourner_client_acheteur();
          if(clients_acheteurs.empty() == 1)
            cout << "impossible, pas de client trouve" << endl;
          else{
            string nom_client;
            int idbien;
            bool proposition;
            int prix;
            cout << "quel est le nom du client : " << endl;                       cin >> nom_client;
            cout << "l'identifiant du bien qui interesse le client : " << endl;   cin >> idbien;
            cout << "le client fait il une proposition (1 ou 0) : " << endl;      cin >> proposition;
            cout << "quel est le prix que le client propose : " << endl;          cin >> prix;
            UnToitPourTous.creer_visite(nom_client, prix, proposition, idbien);
          }
        }
        break;

      // QUITTER LE PROGRAMME
      case 3:
        return 1;
    }
  }
  return 1;
}
