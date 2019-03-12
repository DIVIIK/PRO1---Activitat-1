#include "Comparsa.h"
using namespace std;

Comparsa::Comparsa() {
	/* Pre: cert */
	/* Post: */
	this->nparelles = 0;
    this->parelles = vector<Parella>(MAX_PARELLES);
}

Comparsa::Comparsa(const string &nom) {

}

Comparsa::Comparsa(const string &sigles, const string &nom, const bool ecocaramels) {

}

Comparsa::~Comparsa() {

}

//Modificadors
void Comparsa::afegeixParella(const Parella &parella) {

}

void Comparsa::modificaCarmels() {

}

//Consultors
Parella Comparsa::consultaParella(const int id) const {

}

string Comparsa::consultaSigles() const{

}

ostream& operator<<(ostream &os, const Comparsa &comparsa) {
	os << this-> << "(" << sigles << ", " << this->nom << ", " << this->ecocaramels << ")" << endl 
	<< "Llistat de Parelles" << this->membres[0].dni << " " << this->membres[1].dni;
}

istream& operator>>(istream &is, Comparsa &comparsa) {
	is >> this->
}