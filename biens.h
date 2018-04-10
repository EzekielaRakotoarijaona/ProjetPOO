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
  Biens(int prix, std::string adresse, int surface, int reference, if id)
    {
      prix_bien = prix;
      adresse_bien = adresse;
      surface_bien = surface;
      ref_client_vendeur_bien = reference;
      id_bien = id;
    };
  inline int retourner_prix() {return prix_bien;};
  inline std::string retourner_adresse() {return adresse_bien;};
  inline int retourner_surface() {return surface_bien;};
  inline std::string retourner_referenceClient() {return ref_client_vendeur_bien;};
  inline int retourner_id() {return id_bien;};
  void virtual afficher();
  inline ~Bien() {};
};

#endif
