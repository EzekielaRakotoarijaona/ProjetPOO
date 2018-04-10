#include <iostream>

class Appartement: public Biens{
protected:
  int nombre_de_piece_appartement;
  int etage;
  bool garage;
  bool cave;
  bool balcon;
  int nombre_appartement_immeuble;
public:
  inline Appartement() {nombre_de_piece_appartement = 0; etage = 0; garage = false; cave = false; balcon = false; nombre_appartement_immeuble = 0;};
  inline Appartement(int _nb_pieces, int _etage, bool _garage, bool _cave, bool _balcon, int _nb_appart_imm) {nombre_de_piece_appartement = _nb_pieces; etage = _etage; garage = _garage; cave = _cave; balcon = _balcon; nombre_appartement_immeuble = _nb_appart_imm;};
  inline int retourner_nombrePieceAppartement() {return nombre_de_piece_appartement;};
  inline int retourner_etage() {return etage;};
  inline bool retourner_garage() {return garage;};
  inline bool retourner_cave() {return cave;};
  inline bool retourner_balcon() {return balcon;};
  inline int retourner_nbAppartImm() {return nombre_appartement_immeuble;};
  inline void afficher() {cout << nombre_de_piece_appartement << endl << etage << endl << garage << endl << cave << endl << balcon << endl << nombre_appartement_immeuble << endl;};
};
