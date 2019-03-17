#include "Comparsa.h"
using namespace std;

Comparsa::Comparsa() {
	/* Pre: cert */
	/* Post: Retorna un objecte tipus comparsa */
	nparelles = 0;
 	parelles = vector<Parella>(MAX_PARELLES);
	ecocaramels = false;
}

Comparsa::Comparsa(const string &nom) {
	/* Pre: cert */
	/* Post: Retorna un objecte tipus comparsa */
	nparelles = 0;
    parelles = vector<Parella>(MAX_PARELLES);
    this->nom = nom;
	ecocaramels = false;
}

Comparsa::Comparsa(const string &sigles, const string &nom, const bool ecocaramels) {
	/* Pre: cert */
	/* Post: Retorna un objecte tipus comparsa */
	nparelles = 0;
    parelles = vector<Parella>(MAX_PARELLES);
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
	if (nparelles < MAX_PARELLES) {
		parelles[nparelles] = parella;
		nparelles++;
	}
}

void Comparsa::modificaCaramels(const bool caramels) {
	/* Pre: caramels es un boolea que indica si es fan servir o no */
	/* Post: Alterna el valor de caramels */
	ecocaramels = caramels;
}

//Consultors
Parella Comparsa::consultaParella(const int id) const {
	/* Pre: id es l'identificador de la parella */
	/* Post: Retorna la parella amb id definit */
	Parella p;
	bool trobat = false;
	unsigned int i = 0;
	while (not trobat and i < nparelles) {
		if (parelles[i].consultaIdentificador() == id) {
			p = parelles[i];
			trobat = true;
		}
		++i;
	}
	return p;
}

string Comparsa::consultaSigles() const{
	/* Pre: cert */
	/* Post: Les sigles de la comparsa */
	return sigles;
}

bool Comparsa::consultaCaramels() const{
	/* Pre: cert */
	/* Post: Cert si fa servir ecocaramels, fals en cas contrari */
	return ecocaramels;
}

int Comparsa::consultanParelles() const{
	/* Pre: cert */
	/* Post: El numero de parelles */
	return nparelles;
}

vector<Parella> Comparsa::consultaParelles() const {
	/* Pre: cert */
	/* Post: Un vector de parelles */
	return parelles;
}

bool Comparsa::existeixParella(const int id) const {
	/* Pre: cert */
	/* Post: Cert si existeix la parella indicada, fals en cas contrari */
	for (unsigned int i = 0; i < nparelles; ++i) {
		if (parelles[i].consultaIdentificador() == id)
			return true;
	}
	return false;
}

ostream & operator << (ostream &os, const Comparsa &comparsa) {
	os << "(" << comparsa.sigles << ", " << comparsa.nom << ", " << comparsa.ecocaramels << ")" << endl
	<< "Llistat de Parelles:" << endl;

	for (unsigned int i = 0; i < comparsa.nparelles; ++i) {
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
