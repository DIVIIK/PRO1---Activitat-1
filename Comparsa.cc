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
	this->ecocaramels = caramels;
}

//Consultors
Parella Comparsa::consultaParella(const int id) const {
	/* Pre: cert */
	/* Post: */
	Parella p;
	bool trobat = false;
	int i = 0;
	while (not trobat and i < this->nparelles) {
		if (this->parelles[i].consultaIdentificador() == id) {
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
	return this->ecocaramels;	
}

ostream & operator << (ostream &os, const Comparsa &comparsa) {
	os << "(" << comparsa.sigles << ", " << comparsa.nom << ", " << comparsa.ecocaramels << ")" << endl
	<< "Llistat de parelles: " << endl;
	
	for (int i = 0; i < comparsa.parelles.size(); ++i) {
		comparsa.parelles[i];
		if(i+1 < comparsa.parelles.size())
			os << cout << endl;
	}

	return os;
}

/*
// Repasar
istream& operator>>(istream &is, Comparsa &comparsa) {
	is >> this->sigles >> this->nom >> this->ecocaramels >> this->parelles;
}*/