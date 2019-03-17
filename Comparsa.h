#include <vector>
#include <iostream>
#include "Parella.h"
using namespace std;

class Comparsa {

private:
	const static int MAX_PARELLES = 40;

	unsigned int nparelles;
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
	Parella consultaParella(const int id) const;
	vector<Parella> consultaParelles() const;
	bool existeixParella(const int id) const;
	bool dadesRepetides(const int id) const;
	string consultaSigles() const;
	bool consultaCaramels() const;
	int consultanParelles() const;

	friend ostream& operator<<(ostream &os, const Comparsa &comparsa);

	friend istream& operator>>(istream &is, Comparsa &comparsa);
};
