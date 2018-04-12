#ifndef MAISON_H
#define MAISON_H

#include <iostream>
#include "biens.h"

class Maison: public Biens{
//Attributs
protected:
  int nombre_pieces;
  bool garage;
  bool jardin;
  bool piscine;
public:
  //Méthodes
  Maison(int prix, std::string adresse, int surface, std::string ref_client, int _id_bien,int _nombre_pieces, bool _garage, bool _jardin, bool _piscine);//Constructeur
  inline int retourner_nombre_pieces(){return nombre_pieces;};
  inline bool retourner_jardin(){ return jardin;};
  inline bool retourner_garage(){return  garage;};
  inline bool retourner_piscine(){return piscine;};
  void afficher();//Méthode qui affiche les infos sur la maison 
  inline ~Maison() {};//Destructeur
};

#endif
