#include <iostream>
#include "terrain.h"
using namespace std;

Terrain::Terrain():{
  constructible = false;
}

Terrain::Terrain(bool _constructible){
  constructible = _constructible;
}

void Terrain::afficher(){
  cout << "constructible : " << constructible << endl;
}
