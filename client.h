#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client{
protected:
  std::string nom;
  std::string adresse;
public:
  inline Client() {nom = "\0"; adresse = "\0";};
  inline Client(std::string n, std::string ad) {nom = n; adresse = ad;};
  inline std::string retourner_nom() {return nom;};
  inline std::string retourner_adresse() {return adresse;};
  inline void afficher() {cout << nom << endl << adresse << endl;};
  inline ~Client() {};
};

#endif
