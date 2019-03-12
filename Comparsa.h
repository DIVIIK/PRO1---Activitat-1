#include <vector>
#include <iostream>
#include "Parella.h"
using namespace std;

class Comparsa {

private:
	const static int MAX_PARELLES = 40;

	int nparelles;
	string sigles;
	string nom;
	bool ecocaramels;
	vector<Parella> parelles;

public:
	//Constructors
	Comparsa();

	Comparsa(const string &nom);

	Comparsa(const string &sigles, const string &nom, const bool ecocaramels);

	~Comparsa();

	//Modificadors
	void afegeixParella(const Parella &parella);

	void modificaCaramels(const bool caramels);

	//Consultors
	int consultaIdentificador() const;
	Parella consultaParella(const int id) const;
	string consultaSigles() const;
	bool consultaCaramels() const;

	friend ostream& operator<<(ostream &os, const Comparsa &comparsa);

	friend istream& operator>>(istream &is, Comparsa &comparsa);
};
