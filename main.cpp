#include <iostream>
#include <cstdlib>  // pour compiler sous windows
using namespace std;
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "locaux_pro.h"
#include "acheteur.h"
#include "vendeur.h"
#include "agence.h"
#include <time.h>

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de creer un id pour les maisons
int create_id_maison(map <int, Maison> v){
    int id = rand()%100000;
    id += 1000000;
    while (v.find(id) != v.end()){
      int id = rand()%100000;
      id += 1000000;
    }
    return id;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de creer un id pour les appartements
int create_id_appartement(map <int, Appartement> v){
  int id = rand()%100000;
  id += 2000000;
  while (v.find(id) != v.end()){
    int id = rand()%100000;
    id += 2000000;
  }
  return id;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de creer un id pour les terrains
int create_id_terrain(map <int, Terrain> v){
  int id = rand()%100000;
  id += 3000000;
  while (v.find(id) != v.end()){
    int id = rand()%100000;
    id += 3000000;
  }
  return id;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de creer un id pour les locaux
int create_id_locaux(map <int, Locaux_pro> v){
  int id = rand()%100000;
  id += 4000000;
  while (v.find(id) != v.end()){
    int id = rand()%100000;
    id += 4000000;
  }
  return id;
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre de gerer les exceptions au cas ou un utilisateur entre une donnee qui n'est pas comprise entre les bornes souhaitees, ou si le type de la variable d'entree est incorrecte
void gestion_exception(int inf_a, int sup_a, int &variable_a_modifier){
  if (inf_a == -1 && sup_a != -1)
    while (variable_a_modifier > sup_a || cin.fail()){
      cout << "erreur de saisie, retapez" << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cin >> variable_a_modifier;
    }

  if (sup_a == -1 && inf_a != -1)
    while (variable_a_modifier < inf_a || cin.fail()){
      cout << "erreur de saisie, retapez" << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cin >> variable_a_modifier;
    }

  if (sup_a != -1 && inf_a != -1)
    while (variable_a_modifier > sup_a || variable_a_modifier < inf_a || cin.fail()){
      cout << "erreur de saisie, retapez" << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cin >> variable_a_modifier;
    }

  if (sup_a == -1 && inf_a == -1)
    while (cin.fail()){
      cout << "erreur de saisie, retapez" << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cin >> variable_a_modifier;
    }
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// cette fonction va permettre a l'utilisateur de choisir ce qu'il veut faire sur le menu principal
void gestion_menu(int &fin, int &commande){
  cout << "\n1 : consulter les visites et les biens disponibles" << "\n2 : gestion des clients et des biens" << "\n3 : quitter" << endl;
  cin >> commande;
  gestion_exception(1, 3, commande);
}

/* ------------------------------------------------------------------------------------------------------------------------- */

// fonction principale
int main(){
  srand(time(NULL));
  // INITIALISATION DES DONNEES
  Agence UnToitPourTous;
  int fin = 0;
  int commande = -1;
  int consult = -1;
  int action = -1;
  system("clear");
  cout << "bienvenue sur votre logiciel de gestion" << endl;

  // BOUCLE, VA PERMETTRE DE FAIRE TOURNER LE PROGRAMME ----------------------------------------------------------------
  while (fin == 0){
    gestion_menu(fin, commande);
    switch (commande){

      // CONSULTATION DE DONNEES ----------------------------------------------------------------------------------------
      case 1:
        cout << "1 : consulter les visites\n2 : consulter les biens disponibles\n3 : consulter les clients\n4 : consulter les biens d'un client\n5 : rechercher\n6 : retour" << endl;
        cin >> consult;
        gestion_exception(1, 6, consult);
        if (consult == 6) break;

        // ce cas va traiter l'affichage de toutes les visites
        if (consult == 1){
          map <string, Acheteur> client_ach = UnToitPourTous.retourner_client_acheteur();
          map <string, Acheteur>::iterator it;
          for (it = client_ach.begin() ; it != client_ach.end() ; it++)
            it->second.afficher_visites();
        }

        // ce cas va traiter l'affichage de tous les biens
        if (consult == 2)
          UnToitPourTous.afficher_biens();

        // ce cas va traiter l'affichage des clients vendeurs et acheteurs
        if (consult == 3)
          UnToitPourTous.afficher_clients();

        // ce cas va traiter l'affichage des biens d'un vendeur, selon le type de bien
        if (consult == 4)
          UnToitPourTous.afficher_biens_vendeurs();

        // ce cas va permettre d'afficher les id des biens selon les criteres demandes
        if (consult == 5){
          int rech = -1;

          cout << "1 : rechercher un bien selon son prix\n2 : rechercher un bien selon une option particuliere" << endl;
          cin >> rech;

          // recherche selon le prix
          if (rech == 1){
            int prix = -1, operateur = -1, type_de_bien = -1;
            cout << "quel type de bien " << endl;
            cout << "1 : maison\n2 : appartement\n3 : terrain\n4 : locaux pro\n5 : retour" << endl;     cin >> type_de_bien;
            if (type_de_bien == 5)  break;
            gestion_exception(1, 4, type_de_bien);

            cout << "1 : inferieur a\n2 : superieur a" << endl;       cin >> operateur;
            gestion_exception(1, 2, operateur);
            cout << "quel prix : " << endl;                           cin >> prix;
            gestion_exception(0, -1, prix);
            UnToitPourTous.rechercher_bien_selon_prix(operateur, prix, type_de_bien);
          }

          // recherche selon une option
          if (rech == 2){
            bool jardin = 0, piscine = 0, garage = 0, cave = 0, balcon = 0, constructible = 0, stockage = 0;
            int choix = -1;
            cout << "que voulez-vous dans votre bien : " << endl;
            cout << "1 : jardin\n2 : piscine\n3 : garage\n4 : cave\n5 : balcon\n6 : zone constructible\n7 : piece de stockage" << endl;
            cin >> choix;
            gestion_exception(1, 7, choix);
            if (choix == 1) jardin = 1;            if (choix == 2) piscine = 1;
            if (choix == 3) garage = 1;            if (choix == 4) cave = 1;
            if (choix == 5) balcon = 1;            if (choix == 6) constructible = 1;
            if (choix == 7) stockage = 1;
            UnToitPourTous.rechercher_bien_selon_option(jardin, piscine, garage, cave, balcon, constructible, stockage);
          }
        }
        break;

      // GESTION DES CLIENTS, DES BIENS ET DES VISITES -------------------------------------------------------------------
      case 2:
        cout << "1 : ajouter un client\n2 : supprimer client\n3 : ajouter un bien\n4 : supprimer un bien\n5 : ajouter une visite\n6 : acheter un bien\n7 : retour" << endl;
        cin >> action;
        gestion_exception(1, 7, action);
        if (action == 7) break;

        // ce cas va traiter l'ajout d'un client dans la map associée de la classe agence
        if (action == 1){
          int type_client = -1;
          string nom_du_client;
          string adresse_du_client;

          cout << "1 : acheteur\n2 : vendeur\n3 : retour" << endl;     cin >> type_client;
          gestion_exception(1, 3, type_client);
          if (type_client == 3) break;

          cout << "nom du client : " << endl;              cin >> nom_du_client;
          cout << "adresse du client : " << endl;          cin >> adresse_du_client;

          // client acheteur
          if (type_client == 1){
            Acheteur acheteur_a_ajouter(nom_du_client, adresse_du_client);
            UnToitPourTous.ajouter_client_acheteur(acheteur_a_ajouter);
          }

          // client vendeur
          if (type_client == 2){
            Vendeur vendeur_a_ajouter(nom_du_client, adresse_du_client);
            UnToitPourTous.ajouter_client_vendeur(vendeur_a_ajouter);
          }
        }

        // ce cas va traiter la suppression des clients en fonction de leur nom
        if (action == 2){
          int type_client = -1;
          string suppression;

          cout << "1 : acheteur\n2 : vendeur\n3 : retour" << endl;          cin >> type_client;
          gestion_exception(1, 3, type_client);
          if (type_client == 3) break;

          cout << "nom du client a supprimer : " << endl;       cin >> suppression;

          if (type_client == 1)
            UnToitPourTous.supprimer_client_acheteur(suppression);

          if (type_client == 2)
            UnToitPourTous.supprimer_client_vendeur(suppression);
        }

        // ce cas va traiter l'ajout de differents biens
        if (action == 3){
          int type_bien = -1;
          int prix, surface, id_bien;
          string adresse;
          string ref_client;

          cout << "1 : maison\n2 : appartement\n3 : terrain\n4 : locaux pro\n5 : retour" << endl;  cin >> type_bien;
          gestion_exception(1, 5, type_bien);
          if (type_bien == 5) break;

          cout << "prix du bien : " << endl;                 cin >> prix;
          gestion_exception(0, -1, prix);
          cout << "adresse du bien : " << endl;              cin >> adresse;
          cout << "surface du bien : " << endl;              cin >> surface;
          gestion_exception(0, -1, surface);
          cout << "reference du client : " << endl;          cin >> ref_client;

          bool test = UnToitPourTous.existe_ref_client(ref_client);
          if (test == true){

            // ajout d'une maison
            if (type_bien == 1){
              int nombre_pieces, int_garage, int_jardin, int_piscine;
              bool garage, jardin, piscine;

              id_bien = create_id_maison(UnToitPourTous.retourner_maison());
              cout << "nombre de pieces : " << endl;                         cin >> nombre_pieces;
              gestion_exception(1, -1, nombre_pieces);
              cout << "presence d'un garage (1 ou 0) : " << endl;            cin >> int_garage;
              gestion_exception(0, 1, int_garage);
              garage = int_garage;
              cout << "presence d'un jardin (1 ou 0) : " << endl;            cin >> int_jardin;
              gestion_exception(0, 1, int_jardin);
              jardin = int_jardin;
              cout << "presence d'une piscine (1 ou 0) : " << endl;          cin >> int_piscine;
              gestion_exception(0, 1, int_piscine);
              piscine = int_piscine;
              Maison mai(prix, adresse, surface, ref_client, id_bien, nombre_pieces, garage, jardin, piscine);
              UnToitPourTous.ajouter_maison(mai);
            }

            // ajout d'un appartement
            if (type_bien == 2){
              int nombre_de_piece_appartement, etage, int_garage, int_cave, int_balcon, nombre_appartement_immeuble;
              bool garage, cave, balcon;

              id_bien = create_id_appartement(UnToitPourTous.retourner_appartement());
              cout << "nombre de pieces : " << endl;                         cin >> nombre_de_piece_appartement;
              gestion_exception(0, -1, nombre_de_piece_appartement);
              cout << "nombre d'etage : " << endl;                           cin >> etage;
              gestion_exception(0, -1, etage);
              cout << "presence d'un garage (1 ou 0) : " << endl;            cin >> int_garage;
              gestion_exception(0, 1, int_garage);
              garage = int_garage;
              cout << "presence d'une cave (1 ou 0) : " << endl;             cin >> int_cave;
              gestion_exception(0, 1, int_cave);
              cave = int_cave;
              cout << "presence d'un balcon (1 ou 0) : " << endl;            cin >> int_balcon;
              gestion_exception(0, 1, int_balcon);
              balcon = int_balcon;
              cout << "nombre d'appartement dans l'immeuble : " << endl;     cin >> nombre_appartement_immeuble;
              gestion_exception(1, -1, nombre_appartement_immeuble);
              Appartement app(prix, adresse, surface, ref_client, id_bien, nombre_de_piece_appartement, etage, garage, cave, balcon, nombre_appartement_immeuble);
              UnToitPourTous.ajouter_appartement(app);
            }

            // ajout d'un terrain
            if (type_bien == 3){
              bool constructible;
              int int_constructible;

              id_bien = create_id_terrain(UnToitPourTous.retourner_terrain());
              cout << "le terrain est constructible (1 ou 0) : " << endl;     cin >> int_constructible;
              gestion_exception(0, 1, int_constructible);
              constructible = int_constructible;
              Terrain terr(prix, adresse, surface, ref_client, id_bien, constructible);
              UnToitPourTous.ajouter_terrain(terr);
            }

            // ajout de locaux
            if (type_bien == 4){
              int taille_vitrine, int_pieces_stockage;
              bool piece_stockage;

              id_bien = create_id_locaux(UnToitPourTous.retourner_locauxpro());
              cout << "taille de la vitrine : " << endl;                        cin >> taille_vitrine;
              gestion_exception(0, -1, taille_vitrine);
              cout << "presence d'une piece de stockage (1 ou 0) : " << endl;   cin >> int_pieces_stockage;
              gestion_exception(0, 1, int_pieces_stockage);
              piece_stockage = int_pieces_stockage;
              Locaux_pro loc(prix, adresse, surface, ref_client, id_bien, taille_vitrine, piece_stockage);
              UnToitPourTous.ajouter_locaux(loc);
            }
          }
        }

        // ce cas va traiter la suppression d'un bien selon son identifiant
        if (action == 4){
          int type_bien = -1;
          int suppression, prix;
          string nom;

          cout << "1 : maison\n2 : appartement\n3 : terrain\n4 : locaux pro\n5 : retour" << endl;  cin >> type_bien;
          gestion_exception(1, 5, type_bien);
          if (type_bien == 5) break;

          cout << "attention, la suppression du bien va entrainer la suppression des visites associees" << endl;
          cout << "id du bien a supprimer : " << endl;   cin >> suppression;
          gestion_exception(-1, -1, suppression);
          UnToitPourTous.acheter_bien(suppression, nom, prix, true);
        }

        // ce cas va permettre d'ajouter des visites
        if (action == 5){
          map <string, Acheteur> clients_acheteurs = UnToitPourTous.retourner_client_acheteur();
          if (clients_acheteurs.empty() == 1)
            cout << "impossible, pas de client trouve" << endl;
          else {
            string nom_client;
            int idbien, int_proposition, prix;
            bool proposition;

            cout << "quel est le nom du client : " << endl;                       cin >> nom_client;
            cout << "l'identifiant du bien qui interesse le client : " << endl;   cin >> idbien;
            gestion_exception(-1, -1, idbien);
            cout << "le client fait il une proposition (1 ou 0) : " << endl;      cin >> int_proposition;
            gestion_exception(0, 1, int_proposition);
            proposition = int_proposition;
            cout << "quel est le prix que le client propose : " << endl;          cin >> prix;
            gestion_exception(0, -1, prix);
            UnToitPourTous.creer_visite(nom_client, idbien, proposition, prix);
          }
        }

        // ce cas va permettre de supprimer les visites pour le bien concerne, le bien dans l'agence et dans la liste des vendeurs.
        if (action == 6){
          int idbien;
          string nom_acheteur;
          int depense_acheteur = 0;
          cout << "quel est l'id du bien qui a ete achete : " << endl;  cin >> idbien;
          gestion_exception(-1, -1, idbien);
          UnToitPourTous.acheter_bien(idbien, nom_acheteur, depense_acheteur, false);
        }
        break;

      // QUITTER LE PROGRAMME ---------------------------------------------------------------------------------------
      case 3:
        return 1;

      // VALEUR PAR DEFAUT, toute valeur entree par l'utilisateur qui est differente de 1, 2 ou 3 affichera le message d'erreur
      default:
        cout << "option inexistante" << endl;
        break;
    }
  }
  return 1;
}
