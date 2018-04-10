#ifndef BIENS_H
#define BIENS_H

#include <iostream>



class Biens{
protected:
  int prix_bien;
  std::string adresse_bien;
  int surface_bien;
  std::string ref_client_vendeur_bien;
  int id_bien;
public:
  Biens();
  Biens(int prix, std::string adresse, int surface, std::string reference,int id);
  inline int retourner_prix() {return prix_bien;};
  inline std::string retourner_adresse() {return adresse_bien;};
  inline int retourner_surface() {return surface_bien;};
  inline std::string retourner_referenceClient() {return ref_client_vendeur_bien;};
  inline int retourner_id() {return id_bien;};
  void virtual afficher();
  inline ~Biens() {};
};

#endif
