#ifndef MAISON_H
#define MAISON_H

#include <iostream>

class Maison: public Biens{
protected:
  int nombre_pieces;
  bool garage;
  bool jardin;
  bool piscine;
public:
  Maison(int prix, std::string adresse, int surface, std::string ref_client, int _id_bien,int _nombre_pieces, bool _garage, bool _jardin, bool _piscine):Biens(prix, adresse, surface, ref_client, _id_bien)
  inline retourner_jardin(){return jardin;};
  inline retourner_garage(){return  garage;};
  inline retourner_piscine(){return piscine;};
  void afficher();
  inline ~maison() {};
};

#endif
