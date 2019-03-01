#include <vector>
#include "Parella.h"

class Comparsa {

private:
	const int MAX_PARELLES = 40;

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

	void modificaCarmels();

	//Consultors
	Parella consultaParella(const int id) const;
	string consultaSigles();

	friend ostream& operator<<(ostream &os, const Comparsa &comparsa);

};