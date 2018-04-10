#include <iostream>
#include "terrain.h"
using namespace std;

Terrain::Terrain():{
  constructible = false;
  cout << "terrain cree" << endl;
}

Terrain::Terrain(bool _constructible){
  constructible = _constructible;
  cout << "terrain cree" << endl;
}

void Terrain::afficher(){
  cout << "constructible : " << constructible << endl;
}
