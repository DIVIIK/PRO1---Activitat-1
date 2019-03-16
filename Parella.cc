#include "Parella.h"
using namespace std;


Parella::Parella(){
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 0;
    this->membres = vector< vector< string > >(MAX_MEMBRES, vector< string >(2));
}

Parella::Parella(int id){
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 0;
    this->membres = vector< vector< string > >(MAX_MEMBRES, vector< string >(2));
    this->id = id;
}

Parella::Parella(const int id, const string name1, const string dni1, const string name2, const string dni2){
	/* Pre: cert */
	/* Post: el resultat es un cami buit (de longitud 0) */
	this->nmembres = 2;
  this->membres = vector< vector< string > >(MAX_MEMBRES, vector< string >(2));
  this->id = id;
  this->membres[0][0] = name1;
  this->membres[0][1] = dni1;
  this->membres[1][0] = name2;
  this->membres[1][1] = dni2;
}

Parella::~Parella(){
}

void Parella::afegeixMembre(const string &name, const string &dni){
	/* Pre: El nom del membre i el seu dni */
	if (this->nmembres < this->MAX_MEMBRES) {
		this->membres[this->nmembres][0] = name;
		this->membres[this->nmembres][1] = dni;
		this->nmembres++;
	}
}

int Parella::consultaIdentificador() const{
	/* Pre: cert */
	/* Post: Retorna l'identificador de la parella */
	return this->id;
}

vector< vector< string > > Parella::consultaMembres() const {
	/* Pre: cert */
	/* Post: Retorna un vector de vectors amb els dos membres (nom i dni) */
	return this->membres;
}

ostream& operator<<(ostream &os, const Parella &parella) {
	os << parella.id << " " << parella.membres[0][0] <<
		" " << parella.membres[1][0] << " " << parella.membres[0][1] <<
		" " << parella.membres[1][1];

		return os;
}

istream& operator>>(istream &is, Parella &parella) {
	is >> parella.id >> parella.membres[0][0] >> parella.membres[1][0]
		>> parella.membres[0][1] >> parella.membres[1][1];

		return is;
}
