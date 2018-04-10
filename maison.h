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
  inline maison(int prix, std::string adresse, int surface, std::string ref_client, int _id_bien,int _nombre_pieces, bool _garage, bool _jardin, bool _piscine):Biens(prix,adresse,surface,ref_client,_id_bien){nombre_pieces = _nombre_pieces; garage = _garage; jardin = _jardin; piscine = _piscine;};
  inline retourner_nombre_pieces(){return nombre_pieces;};
  inline retourner_jardin(){return jardin;};
  inline retourner_garage(){return  garage;};
  inline retourner_piscine(){return piscine;};
  inline afficher(){std::cout<<nombre_pieces<<garage<<jardin<<piscine<<std::endl;};
  inline ~maison(){};
};

#endif
