#include <iostream>


class Biens{
protected:
  int prix_bien;
  std::string adresse_bien;
  int surface_bien;
  std::string ref_client_vendeur_bien;
  int id_bien;
public:
  inline Bien() {prix_bien = 0; adresse_bien = "\0"; surface_bien = 0; ref_client_vendeur_bien = "\0"; id_bien = 0;};
  inline Bien(int prix, std::string adresse, int surface, int reference, if id) {prix_bien = prix; adresse_bien = adresse; surface_bien = surface; ref_client_vendeur_bien = reference; id_bien = id;};
  inline int retourner_prix() {return prix_bien;};
  inline std::string retourner_adresse() {return adresse_bien;};
  inline int retourner_surface() {return surface_bien;};
  inline std::string retourner_referenceClient() {return ref_client_vendeur_bien;};
  inline int retourner_id() {return id_bien;};
  inline void virtual afficher() {cout << prix_bien << endl << adresse_bien << endl << surface_bien << endl << ref_client_vendeur_bien << endl << id_bien << endl;};
  inline ~Bien() {};
};
