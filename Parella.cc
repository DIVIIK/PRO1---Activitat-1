include "Parella.h"

Parella:Parella() {
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 0;
    this->parelles = vector<Parella>(MAX_MEMRES);
}

Parella:Parella(int id) {
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 0;
    this->parelles = vector<Parella>(MAX_MEMRES);
    this->id = id;
}

Parella:Parella(int id, Membre &membre1, Membre &membre2) {
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 0;
  this->parelles = vector<Parella>(MAX_MEMRES);
  this->id = id;
  this->membres[0] = membre1;
  this->membres[1] = membre2;
}

Parella::~Parella(){
}

void Parella::afegeixMembre(const Membre &membre) {
	if (this->nmembres < this->MAX_MEMRES) {
		this.membres[this->nmembres] = membre;
		this->nmembres++;
	}
}


Membre Parella::consultaMembre(const string &dni) {
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

int Parella::consultaIdentificador() {

}
