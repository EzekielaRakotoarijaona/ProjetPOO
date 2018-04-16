#include <iostream>
#include <fstream>
#include <algorithm> // pour compiler sous windows
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

int decode_id(int id){
  id = id/1000000;
  return id;
}

// constructeur agence
Agence::Agence(){
  clients_vendeurs.empty();
  clients_acheteurs.empty();
  _appartement.empty();
  _maison.empty();
  _terrain.empty();
  _locauxpro.empty();
  cout << "agence creee" << endl << endl;
  ifstream file;

  //lecture vendeur.txt
  file.open("vendeur.txt");
  if(!file){
    cout <<"vendeur.txt inexistant, creation en cours..." << endl;
    return;
  }
  string nom;
  string adresse;

  while(true){
    if(file.eof())  break;
    getline(file, nom);

    if(file.eof())  break;
    getline(file, adresse);

    Vendeur v(nom, adresse);
    ajouter_client_vendeur(v);
  }
  cout << "vendeur charge" << endl;
  file.close();

  //lecture maison.txt
  file.open("maison.txt");
  if(!file){
    cout <<"maison.txt inexistant, creation en cours..." << endl;
    return;
  }
  string prix_bien;       int prix;
  string adresse_bien;
  string surface_bien;    int surface;
  string reference;
  string id_bien;         int id;
  string nombre_pieces;   int pieces;
  string _garage;         int garage;
  string _jardin;         int jardin;
  string _piscine;        int piscine;

  while(true){
    getline(file, prix_bien);
    if(file.eof())  break;
    prix = stoi(prix_bien);

    getline(file, adresse_bien);
    if(file.eof())  break;

    getline(file, surface_bien);
    if(file.eof())  break;
    surface = stoi(surface_bien);

    getline(file, reference);
    if(file.eof())  break;

    getline(file, id_bien);
    if(file.eof())  break;
    id = stoi(id_bien);

    getline(file, nombre_pieces);
    if(file.eof())  break;
    pieces = stoi(nombre_pieces);

    getline(file, _garage);
    if(file.eof())  break;
    garage = stoi(_garage);

    getline(file, _jardin);
    if(file.eof())  break;
    jardin = stoi(_jardin);

    getline(file, _piscine);
    if(file.eof())  break;
    piscine = stoi(_piscine);

    Maison m(prix, adresse_bien, surface, reference, id, pieces, garage, jardin, piscine);
    this->ajouter_maison(m);
  }
  cout << "maison charge" << endl;
  file.close();

  //lecture appartement.txt
  file.open("appartement.txt");
  if(!file){
    cout <<"appartement.txt inexistant, creation en cours..." << endl;
    return;
  }
  string nombre_de_piece_appartement;  int nb_pieces_appartement;
  string _etage;                       int etage;
  string _cave;                        int cave;
  string _balcon;                      int balcon;
  string nombre_appartement_immeuble;  int nb_appartement_immeuble;
  while(true){
    getline(file, prix_bien);
    if(file.eof())  break;
    prix = stoi(prix_bien);

    getline(file, adresse_bien);
    if(file.eof())  break;

    getline(file, surface_bien);
    if(file.eof())  break;
    surface = stoi(surface_bien);

    getline(file, reference);
    if(file.eof())  break;

    getline(file, id_bien);
    if(file.eof())  break;
    id = stoi(id_bien);

    getline(file, nombre_de_piece_appartement);
    if(file.eof())  break;
    nb_pieces_appartement = stoi(nombre_de_piece_appartement);

    getline(file, _etage);
    if(file.eof())  break;
    etage = stoi(_etage);

    getline(file, _garage);
    if(file.eof())  break;
    garage = stoi(_garage);

    getline(file, _cave);
    if(file.eof())  break;
    cave = stoi(_cave);

    getline(file, _balcon);
    if(file.eof())  break;
    balcon = stoi(_balcon);

    getline(file, nombre_appartement_immeuble);
    if(file.eof())  break;
    nb_appartement_immeuble = stoi(nombre_appartement_immeuble);

    Appartement a(prix, adresse_bien, surface, reference, id, nb_pieces_appartement, etage, garage, cave, balcon, nb_appartement_immeuble);
    this->ajouter_appartement(a);
  }
  cout << "appartement charge" << endl;
  file.close();

  //lecture locaux_pro.txt
  file.open("locaux_pro.txt");
  if(!file){
    cout <<"locaux_pro.txt inexistants, creation en cours..." << endl;
    return;
  }
  string taille;    int taille_vitrine;
  string stockage;  int piece_stockage;
  while(true){
    getline(file, prix_bien);
    if(file.eof())  break;
    prix = stoi(prix_bien);

    getline(file, adresse_bien);
    if(file.eof())  break;

    getline(file, surface_bien);
    if(file.eof())  break;
    surface = stoi(surface_bien);

    getline(file, reference);
    if(file.eof())  break;

    getline(file, id_bien);
    if(file.eof())  break;
    id = stoi(id_bien);

    getline(file, taille);
    if(file.eof())  break;
    taille_vitrine = stoi(taille);

    getline(file, stockage);
    if(file.eof())  break;
    piece_stockage = stoi(stockage);

    Locaux_pro l(prix, adresse_bien, surface, reference, id, taille_vitrine, piece_stockage);
    this->ajouter_locaux(l);
  }
  cout << "locaux_pro charges" << endl;
  file.close();

  //lecture terrain.txt
  file.open("terrain.txt");
  if(!file){
    cout <<"terrain.txt inexistant, creation en cours..." << endl;
    return;
  }
  string construct;  int constructible;
  while(true){
    getline(file, prix_bien);
    if(file.eof())  break;
    prix = stoi(prix_bien);

    getline(file, adresse_bien);
    if(file.eof())  break;

    getline(file, surface_bien);
    if(file.eof())  break;
    surface = stoi(surface_bien);

    getline(file, reference);
    if(file.eof())  break;

    getline(file, id_bien);
    if(file.eof())  break;
    id = stoi(id_bien);

    getline(file, construct);
    if(file.eof())  break;
    constructible = stoi(construct);

    Terrain t(prix, adresse_bien, surface, reference, id, constructible);
    this->ajouter_terrain(t);
  }
  cout << "terrain charge" << endl;
  file.close();

  //lecture acheteur.txt
  file.open("acheteur.txt");
  if(!file){
    cout <<"acheteur.txt inexistant, creation en cours...\n";
    return;
  }
  string str_size;          int size;
  string str_id;
  string str_proposition;   int proposition;
  string str_prix;
  while(true){
    if(file.eof())  break;
    getline(file, nom);

    if(file.eof())  break;
    getline(file, adresse);

    Acheteur a(nom, adresse);
    this->ajouter_client_acheteur(a);

    getline(file, str_size);
    if(file.eof())  break;
    size = stoi(str_size);

    for(int i = 0; i < size; i++){
      getline(file, str_id);
      if(file.eof())  break;
      id = stoi(str_id);

      getline(file, str_proposition);
      if(file.eof())  break;
      proposition = stoi(str_proposition);

      getline(file, str_prix);
      if(file.eof())  break;
      prix = stoi(str_prix);

      this->creer_visite(nom, id, proposition, prix);
    }
  }
  cout << "acheteur charge" << endl;
  file.close();
}


void Agence::ajouter_maison(Maison m){
  _maison.insert(std::make_pair(m.retourner_id(),m));
  string ref = m.retourner_referenceClient();
  map <string, Vendeur>::iterator it = clients_vendeurs.find(ref);
  it->second.ajouter_bien(m.retourner_id());
}

void Agence::ajouter_appartement(Appartement a){
  _appartement.insert(std::make_pair(a.retourner_id(),a));
  string ref = a.retourner_referenceClient();
  map <string, Vendeur>::iterator it = clients_vendeurs.find(ref);
  it->second.ajouter_bien(a.retourner_id());
}

void Agence::ajouter_terrain(Terrain t){
  _terrain.insert(std::make_pair(t.retourner_id(),t));
  string ref = t.retourner_referenceClient();
  map <string, Vendeur>::iterator it = clients_vendeurs.find(ref);
  it->second.ajouter_bien(t.retourner_id());
}

void Agence::ajouter_locaux(Locaux_pro l){
  _locauxpro.insert(std::make_pair(l.retourner_id(),l));
  string ref = l.retourner_referenceClient();
  map <string, Vendeur>::iterator it = clients_vendeurs.find(ref);
  it->second.ajouter_bien(l.retourner_id());
}


void Agence::afficher_biens_vendeurs(){
  string nom;
  cout << "nom du client :" << endl;
  cin >> nom;
  map <string, Vendeur>::iterator it = clients_vendeurs.find(nom);
  if(it == clients_vendeurs.end()){
    cout << "client introuvable" << endl;
    return;
  }
  it->second.afficher_b();
}

// methode ajouter client vendeur
void Agence::ajouter_client_vendeur(Vendeur c){
  clients_vendeurs.insert(make_pair(c.retourner_nom(),c));
  cout << "Client Ajoute" << endl << endl;
}

// methode ajouter client acheteur
void Agence::ajouter_client_acheteur(Acheteur c){
  clients_acheteurs.insert(make_pair(c.retourner_nom(),c));
  cout << "Client Ajoute" << endl << endl;
}

//Methode supprimer client vendeur
void Agence::supprimer_client_vendeur(string nom){
  map <string, Vendeur>::iterator it;
  it = clients_vendeurs.find(nom);
  if(it == clients_vendeurs.end()){
    cout << "introuvable" << endl;
    return;
  }
  //Acceder a l'objet vendeur puis a son tableau de bien et supprimer tous les biens de ce vendeur
  vector<int> tab_bien = it->second.retourner_tableauBien();
  int type;
  for(int i = 0; i < tab_bien.size(); i++){
    type = decode_id(tab_bien[i]);

    if(type == 1){
      map <int, Maison>::iterator it1;
      it1 = _maison.find(tab_bien[i]);
      _maison.erase(it1);
    }

    if(type == 2){
      map <int, Appartement>::iterator it2;
      it2 = _appartement.find(tab_bien[i]);
      _appartement.erase(it2);
    }

    if(type == 3){
      map <int, Terrain>::iterator it3;
      it3 = _terrain.find(tab_bien[i]);
      _terrain.erase(it3);
    }

    if(type == 4){
      map <int, Locaux_pro>::iterator it4;
      it4 = _locauxpro.find(tab_bien[i]);
      _locauxpro.erase(it4);
    }
  }
  clients_vendeurs.erase(it);
  cout << "Client vendeur supprime" << endl << endl;
}

// methode de suppression des clients acheteur
void Agence::supprimer_client_acheteur(string nom){
  map <string, Acheteur>::iterator it;
  it = clients_acheteurs.find(nom);
  if(it == clients_acheteurs.end()){
    cout << "introuvable" << endl;
    return;
  }
  clients_acheteurs.erase(it);
  cout << "Client acheteur supprime" << endl << endl;
}

// methode de suppression des appartements
void Agence::supprimer_appartement(int id){
  map <int, Appartement>::iterator it;
  it = _appartement.find(id);
  if(it == _appartement.end()){
    cout << "introuvable" << endl;
    return;
  }
  string nom = it->second.retourner_referenceClient();
  map <string, Vendeur>::iterator it1;
  it1 = clients_vendeurs.find(nom);
  it1->second.retirer_bien(id);
  _appartement.erase(it);
  cout << "appartement supprime" <<endl << endl;
}

// Methode de suppression des maison
void Agence::supprimer_maison(int id){
  map <int, Maison>::iterator it;
  it = _maison.find(id);
  if(it == _maison.end()){
    cout << "introuvable" << endl;
    return;
  }
  string nom = it->second.retourner_referenceClient();
  map <string, Vendeur>::iterator it1;
  it1 = clients_vendeurs.find(nom);
  it1->second.retirer_bien(id);
  _maison.erase(it);
  cout << "maison supprimee" << endl << endl;
}

 //Methode de suppression des terrains
void Agence::supprimer_terrain(int id){
  map <int, Terrain>::iterator it;
  it = _terrain.find(id);
  if(it == _terrain.end()){
    cout << "introuvable" << endl;
    return;
  }
  string nom = it->second.retourner_referenceClient();
  map <string, Vendeur>::iterator it1;
  it1 = clients_vendeurs.find(nom);
  it1->second.retirer_bien(id);
  _terrain.erase(it);
  cout << "terrain supprime" << endl << endl;
}

 //methode de suppression des locaux
void Agence::supprimer_locaux(int id){
  map <int, Locaux_pro>::iterator it;
  it = _locauxpro.find(id);
  if(it == _locauxpro.end()){
    cout << "introuvable" << endl;
    return;
  }
  string nom = it->second.retourner_referenceClient();
  map <string, Vendeur>::iterator it1;
  it1 = clients_vendeurs.find(nom);
  it1->second.retirer_bien(id);
  _locauxpro.erase(it);
  cout << "locaux supprimes" << endl << endl;
}

//Methode afficher biens
void Agence::afficher_biens(){
  int type = -1;
  cout << "quel type de bien ?" << endl;
  cout << "1 : maison\n2 : appartement\n3 : terrain\n4 : locaux pro" << endl;
  cin >> type;
  map <int, Maison> mai = retourner_maison();
  map <int, Maison>::iterator it;
  map <int, Appartement> app = retourner_appartement();
  map <int, Appartement>::iterator it2;
  map <int, Terrain> terr = retourner_terrain();
  map <int, Terrain>::iterator it3;
  map <int, Locaux_pro> loc = retourner_locauxpro();
  map <int, Locaux_pro>::iterator it4;

  switch(type){
    case 1:
      for(it = mai.begin() ; it != mai.end() ; it++)
        it->second.afficher();
      break;

    case 2:
      for(it2 = app.begin() ; it2 != app.end() ; it2++)
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


void Agence::creer_visite(string nom, int idbien, bool proposition, int prix){
  map <string, Acheteur>::iterator it;
  it = clients_acheteurs.find(nom);
  if(it == clients_acheteurs.end()){
    cout << "client introuvable" << endl;
    return;
  }
  it->second.ajouter_visite(prix, proposition, idbien);
}


void Agence::acheter_bien(int idbien){
  string nom_vendeur;
  int id = decode_id(idbien);
  int id_valide = existe_bien(id, idbien, nom_vendeur);

  if (id < 1 || id > 4 || id_valide == false)
    return;

  // supprimer la visite
  for(map <string, Acheteur>::iterator it = clients_acheteurs.begin() ; it != clients_acheteurs.end() ; it++)
    it->second.supprimer_visite(idbien);

  // supprimer le bien du vendeur
  map <string, Vendeur>::iterator it2;
  it2 = clients_vendeurs.find(nom_vendeur);
  it2->second.retirer_bien(idbien);

  // supprimer le bien dans l'agence
  if (id == 1)
    supprimer_maison(idbien);
  if (id == 2)
    supprimer_appartement(idbien);
  if (id == 3)
    supprimer_terrain(idbien);
  if (id == 4)
    supprimer_locaux(idbien);
}

//Methode afficher clients
void Agence::afficher_clients(){
  int type = -1;
  cout << "quel type de client ?" << endl;
  cout << "1 : acheteur\n2 : vendeur" << endl;
  cin >> type;
  if (type == 1)
    for(map <string, Acheteur>::iterator it = clients_acheteurs.begin() ; it != clients_acheteurs.end() ; it++)
      it->second.afficher_acheteur();
  if (type == 2)
    for(map <string, Vendeur>::iterator it2 = clients_vendeurs.begin() ; it2 != clients_vendeurs.end() ; it2++)
      it2->second.afficher_vendeur();
}

bool Agence::existe_ref_client(string ref_client){
  map <string, Vendeur> clients_vendeurs = retourner_client_vendeur();
  map <string, Vendeur>::iterator it;
  it = clients_vendeurs.find(ref_client);
  if(it == clients_vendeurs.end()){
    cout << "erreur : client non trouve" << endl;
    return false;
  }
  return true;
}

bool Agence::existe_bien(int bien, int idbien, string &nom){
  switch(bien){
    case 1: // maison
    {
      map <int, Maison> mai = retourner_maison();
      for(map <int, Maison>::iterator it = mai.begin() ; it != mai.end() ; it++)
        if (idbien == it->second.retourner_id()){
          nom = it->second.retourner_referenceClient();
          return true;
        }
      return false;
    }

    case 2: // appartement
    {
      map <int, Appartement> app = retourner_appartement();
      for(map <int, Appartement>::iterator it = app.begin() ; it != app.end() ; it++)
        if (idbien == it->second.retourner_id()){
          nom = it->second.retourner_referenceClient();
          return true;
        }
      return false;
    }

    case 3: // terrain
    {
      map <int, Terrain> terr = retourner_terrain();
      for(map <int, Terrain>::iterator it = terr.begin() ; it != terr.end() ; it++)
        if (idbien == it->second.retourner_id()){
          nom = it->second.retourner_referenceClient();
          return true;
        }
      return false;
    }

    case 4: // locaux pro
    {
      map <int, Locaux_pro> loc = retourner_locauxpro();
      for(map <int, Locaux_pro>::iterator it = loc.begin() ; it != loc.end() ; it++)
        if (idbien == it->second.retourner_id()){
          nom = it->second.retourner_referenceClient();
          return true;
        }
      return false;
    }
  }
  return false;
}

void Agence::rechercher_bien_selon_prix(int operateur, int prix, int bien){
  switch(bien){
    case 1: // maison
    {
      map <int, Maison> mai = retourner_maison();
      for(map <int, Maison>::iterator it = mai.begin() ; it != mai.end() ; it++){
        if (operateur == 1)
          if (it->second.retourner_prix() < prix)
            cout << "id : " << it->second.retourner_id() << endl;
        if (operateur == 2)
          if (it->second.retourner_prix() > prix)
            cout << "id : " << it->second.retourner_id() << endl;
      }
      break;
    }
    case 2: // appartement
    {
      map <int, Appartement> app = retourner_appartement();
      for(map <int, Appartement>::iterator it = app.begin() ; it != app.end() ; it++){
        if (operateur == 1)
          if (it->second.retourner_prix() < prix)
            cout << "id : " << it->second.retourner_id() << endl;
        if (operateur == 2)
          if (it->second.retourner_prix() > prix)
            cout << "id : " << it->second.retourner_id() << endl;
      }
      break;
    }
    case 3: // terrain
    {
      map <int, Terrain> terr = retourner_terrain();
      for(map <int, Terrain>::iterator it = terr.begin() ; it != terr.end() ; it++){
        if (operateur == 1)
          if (it->second.retourner_prix() < prix)
            cout << "id : " << it->second.retourner_id() << endl;
        if (operateur == 2)
          if (it->second.retourner_prix() > prix)
            cout << "id : " << it->second.retourner_id() << endl;
      }
      break;
    }
    case 4: // locaux pro
    {
      map <int, Locaux_pro> loc = retourner_locauxpro();
      for(map <int, Locaux_pro>::iterator it = loc.begin() ; it != loc.end() ; it++){
        if (operateur == 1)
          if (it->second.retourner_prix() < prix)
            cout << "id : " << it->second.retourner_id() << endl;
        if (operateur == 2)
          if (it->second.retourner_prix() > prix)
            cout << "id : " << it->second.retourner_id() << endl;
      }
      break;
    }
  }
}

Agence::~Agence(){
    ofstream file;
    file.open("vendeur.txt",std::ofstream::out | std::ofstream::trunc);
    if(!file){
  		cout<<"Error in creating file...\n";
  		return;
  	}
    for(map <string, Vendeur>::iterator it2 = clients_vendeurs.begin() ; it2 != clients_vendeurs.end() ; it2++){
      file << it2->second.retourner_nom() << endl;
      file << it2->second.retourner_adresse() << endl;
    }
    cout << "vendeur sauvegarde" << endl;
    file.close();
    file.open("maison.txt",std::ofstream::out | std::ofstream::trunc);
    if(!file){
  		cout<<"Error in creating file...\n";
  		return;
  	}
    for(map <int, Maison>::iterator it = _maison.begin() ; it != _maison.end() ; it++){
      file << it->second.retourner_prix() << endl;
      file << it->second.retourner_adresse() << endl;
      file << it->second.retourner_surface() << endl;
      file << it->second.retourner_referenceClient() << endl;
      file << it->second.retourner_id() << endl;
      file << it->second.retourner_nombre_pieces() << endl;
      file << it->second.retourner_garage() << endl;
      file << it->second.retourner_jardin() << endl;
      file << it->second.retourner_piscine() << endl;
    }
    cout << "maison sauvegarde" << endl;
    file.close();
    file.open("appartement.txt",std::ofstream::out | std::ofstream::trunc);
    if(!file){
  		cout<<"Error in creating file...\n";
  		return;
  	}
    for(map <int, Appartement>::iterator it3 = _appartement.begin() ; it3 != _appartement.end() ; it3++){
      file << it3->second.retourner_prix() << endl;
      file << it3->second.retourner_adresse() << endl;
      file << it3->second.retourner_surface() << endl;
      file << it3->second.retourner_referenceClient() << endl;
      file << it3->second.retourner_id() << endl;
      file << it3->second.retourner_nombrePieceAppartement() << endl;
      file << it3->second.retourner_etage() << endl;
      file << it3->second.retourner_garage() << endl;
      file << it3->second.retourner_cave() << endl;
      file << it3->second.retourner_balcon() << endl;
      file << it3->second.retourner_nbAppartImm() << endl;
    }
    cout << "appartement sauvegarde" << endl;
    file.close();
    file.open("locaux_pro.txt",std::ofstream::out | std::ofstream::trunc);
    if(!file){
  		cout<<"Error in creating file...\n";
  		return;
  	}
    for(map <int, Locaux_pro>::iterator it4 = _locauxpro.begin() ; it4 != _locauxpro.end() ; it4++){
      file << it4->second.retourner_prix() << endl;
      file << it4->second.retourner_adresse() << endl;
      file << it4->second.retourner_surface() << endl;
      file << it4->second.retourner_referenceClient() << endl;
      file << it4->second.retourner_id() << endl;
      file << it4->second.retourner_taille() << endl;
      file << it4->second.retourner_stockage() << endl;
    }
    file.close();
    cout << "locaux sauvegarde" << endl;
    file.open("terrain.txt",std::ofstream::out | std::ofstream::trunc);
    if(!file){
  		cout<<"Error in creating file...\n";
  		return;
  	}
    for(map <int, Terrain>::iterator it5 = _terrain.begin() ; it5 != _terrain.end() ; it5++){
      file << it5->second.retourner_prix() << endl;
      file << it5->second.retourner_adresse() << endl;
      file << it5->second.retourner_surface() << endl;
      file << it5->second.retourner_referenceClient() << endl;
      file << it5->second.retourner_id() << endl;
      file << it5->second.retourner_constructible() << endl;
    }
    file.close();
    cout << "terrain sauvegarde" << endl;
    file.open("acheteur.txt",std::ofstream::out | std::ofstream::trunc);
    if(!file){
  		cout<<"Error in creating file...\n";
  		return;
  	}
    for(map <string, Acheteur>::iterator it6 = clients_acheteurs.begin() ; it6 != clients_acheteurs.end() ; it6++){
      file << it6->second.retourner_nom() << endl;
      file << it6->second.retourner_adresse() << endl;
      vector<int> id = it6->second.retourner_idbien();
      vector<bool> proposition = it6->second.retourner_proposition();
      vector<int> prix = it6->second.retourner_prix();
      int size = id.size();
      file << size << endl;
      for(int i = 0; i < size; i++){
        file << id[i] << endl;
        file << proposition[i] << endl;
        file << prix[i] << endl;
      }
    }
    cout << "acheteur sauvegarde" << endl;
    file.close();
}
