#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client{
  //Attributs
protected:
  std::string nom;
  std::string adresse;
//Méthodes
public:
  Client();
  Client(std::string n, std::string ad);
  inline std::string retourner_nom() {return nom;};
  inline std::string retourner_adresse() {return adresse;};
  void afficher();//Méthode afficher client
  inline ~Client() {};//Destructeur
};

#endif
