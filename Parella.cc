#include "Parella.h"
using namespace std;

Parella::Parella(){
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 0;
    this->membres = vector<Membre>(MAX_MEMBRES);
}

Parella::Parella(int id){
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 0;
    this->membres = vector<Membre>(MAX_MEMBRES);
    this->id = id;
}

Parella::Parella(const int id,const Membre &membre1,const Membre &membre2){
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 0;
  this->membres = vector<Membre>(MAX_MEMBRES);
  this->id = id;
  this->membres[0] = membre1;
  this->membres[1] = membre2;
}

Parella::~Parella(){
}

void Parella::afegeixMembre(const Membre &membre){
	if (this->nmembres < this->MAX_MEMBRES) {
		this->membres[this->nmembres] = membre;
		this->nmembres++;
	}
}


	Membre Parella::consultaMembre(const string &dni){
	Membre mem;
	bool trobat = false;
	int i = 0;
	while (not trobat and i < this->nmembres) {
		if (this->membres[i].dni == dni) {
			mem = this->membres[i];
			trobat = true;
		}
		++i;
	}
	return mem;
}

int Parella::consultaIdentificador(){
	return this->id;
}
