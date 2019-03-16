#include "Comparsa.h"
using namespace std;

Comparsa::Comparsa() {
	/* Pre: cert */
	/* Post: Retorna un objecte tipus comparsa */
	this->nparelles = 0;
  this->parelles = vector<Parella>(MAX_PARELLES);
	this->ecocaramels = false;
}

Comparsa::Comparsa(const string &nom) {
	/* Pre: cert */
	/* Post: Retorna un objecte tipus comparsa */
	this->nparelles = 0;
    this->parelles = vector<Parella>(MAX_PARELLES);
    this->nom = nom;
		this->ecocaramels = false;
}

Comparsa::Comparsa(const string &sigles, const string &nom, const bool ecocaramels) {
	/* Pre: cert */
	/* Post: Retorna un objecte tipus comparsa */
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
	/* Pre: Una parella de persones */
	/* Post: Introdueix a la comparsa la nova parella */
	if (this->nparelles < this->MAX_PARELLES) {
		this->parelles[this->nparelles] = parella;
		this->nparelles++;
	}
}

void Comparsa::modificaCaramels(const bool caramels) {
	/* Pre: caramels es un boolea que indica si es fan servir o no */
	/* Post: Alterna el valor de caramels */
	this->ecocaramels = caramels;
}

//Consultors
Parella Comparsa::consultaParella(const int id) const {
	/* Pre: id es l'identificador de la parella */
	/* Post: Retorna la parella amb id definit */
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
	/* Post: Les sigles de la comparsa */
	return this->sigles;
}

bool Comparsa::consultaCaramels() const{
	/* Pre: cert */
	/* Post: Cert si fa servir ecocaramels, fals en cas contrari */
	return this->ecocaramels;
}

int Comparsa::consultanParelles() const{
	/* Pre: cert */
	/* Post: El numero de parelles */
	return this->nparelles;
}

vector<Parella> Comparsa::consultaParelles() const {
	/* Pre: cert */
	/* Post: Un vector de parelles */
	return this->parelles;
}

bool Comparsa::existeixParella(const int id) const {
	/* Pre: cert */
	/* Post: Cert si existeix la parella indicada, fals en cas contrari */
	for (int i = 0; i < this->nparelles; ++i) {
		if (this->parelles[i].consultaIdentificador() == id)
			return true;
	}
	return false;
}

ostream & operator << (ostream &os, const Comparsa &comparsa) {
	os << "(" << comparsa.sigles << ", " << comparsa.nom << ", " << comparsa.ecocaramels << ")" << endl
	<< "Llistat de Parelles:" << endl;

	for (int i = 0; i < comparsa.nparelles; ++i) {
		os << comparsa.parelles[i];
		if(i+1 < comparsa.parelles.size())
			os << endl;
	}
	return os;
}

istream& operator>>(istream &is, Comparsa &comparsa) {
	is >> comparsa.nom;
	for (int i = 0; i < 4; ++i) {
		comparsa.sigles += toupper(comparsa.nom[i]);
	}
	return is;
}
