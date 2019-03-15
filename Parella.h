#include <vector>
#include <iostream>

using namespace std;

class Parella {

private:

    vector< vector< string > > membres;
    int id;
    int nmembres;
    const static int MAX_MEMBRES = 2;

public:


    //Constructors
    Parella();

    Parella(const int id);

    Parella(const int id, const string name1, const string dni1, const string name2, const string dni2);

    ~Parella();

    //Modificadors
    void afegeixMembre(const string &name, const string &dni);

    //Consultors

    int consultaIdentificador() const;

    friend ostream& operator<<(ostream &os, const Parella &parella);

    friend istream& operator>>(istream &is, Parella &parella);
};
