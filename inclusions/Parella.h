#include <vector>
#include <iostream>

using namespace std;

class Parella {

private:
    typedef struct {
        string nom;
        string dni;
    }Membre;

    vector<Membre> membres;
    int id;
    int nmembres;
    const static int MAX_MEMBRES = 2;

public:

    //Constructors
    Parella();

    Parella(const int id);

    Parella(const int id, const Membre &membre1, const Membre &membre2);

    ~Parella();

    //Modificadors
    void afegeixMembre(const Membre &membre);

    //Consultors
    Membre consultaMembre(const string &dni) const;

    int consultaIdentificador();

    friend ostream& operator<<(ostream &os, const Parella &parella);

    friend istream& operator>>(istream &is, Parella &parella);
};
