#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client{
protected:
  std::string nom;
  std::string adresse;
public:
  Client();
  Client(std::string n, std::string ad) {nom = n; adresse = ad;};
  inline std::string retourner_nom() {return nom;};
  inline std::string retourner_adresse() {return adresse;};
  void afficher();
  inline ~Client() {};
};

#endif
