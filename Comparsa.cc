#include "Comparsa.h"
using namespace std;

Comparsa::Comparsa() {
	/* Pre: cert */
	/* Post: */
	this->nparelles = 0;
    this->parelles = vector<Parella>(MAX_PARELLES);
}

Comparsa::Comparsa(const string &nom) {
	/* Pre: cert */
	/* Post: */
	this->nparelles = 0;
    this->parelles = vector<Parella>(MAX_PARELLES);
    this->nom = nom;
}

Comparsa::Comparsa(const string &sigles, const string &nom, const bool ecocaramels) {
	/* Pre: cert */
	/* Post: */
	this->nparelles = 0;
    this->parelles = vector<Parella>(MAX_PARELLES);
    this->nom = nom;
    this->sigles = sigles;
    this->ecocaramels = ecocaramels;
}

Comparsa::~Comparsa() {

}

//Modificadors
void Comparsa::afegeixParella(const Parella &parella) {
	/* Pre: cert */
	/* Post: */
	if (this->nparelles < this->MAX_PARELLES) {
		this->parelles[this->nparelles] = parella;
		this->nparelles++;
	}
}

void Comparsa::modificaCaramels(const bool caramels) {
	/* Pre: cert */
	/* Post: */
	this->caramels = caramels;
}

//Consultors
int Comparsa::consultaIdentificador(){
	return this->id;
}

Parella Comparsa::consultaParella(const int id) const {
	/* Pre: cert */
	/* Post: */
	Parella p;
	bool trobat = false;
	int i = 0;
	while (not trobat and i < this->nparelles) {
		if (this->nparelles[i].id == id) {
			p = this->parelles[i];
			trobat = true;
		}
		++i;
	}
	return p;
}

string Comparsa::consultaSigles() const{
	/* Pre: cert */
	/* Post: */
	return this->sigles;
}

bool Comparsa::consultaCaramels() const{
	/* Pre: cert */
	/* Post: */
	return this->caramels;	
}

ostream& operator<<(ostream &os, const Comparsa &comparsa) {
	os << "(" << this->sigles << ", " << this->nom << ", " << this->ecocaramels << ")" << endl
	<< "Llistat de parelles: " << endl;
	
	// Aixo es correcte?
	for (int i = 0; i < this->parelles.size(); ++i) {
		this->parelles[i];
		if(i+1 < this->parelles.size()) cout << endl;
	}

}

// Repasar
istream& operator>>(istream &is, Comparsa &comparsa) {
	is >> this->sigles >> this->nom >> this->ecocaramels >> this->parelles;
}