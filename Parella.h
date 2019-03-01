#include <vector>

class Parella {

private:
    struct Membre
    {
        string nom;
        string dni;
    };

    vector<Membre> membres;
    int id;
    int nmembres;
    const int MAX_MEMBRES = 2;

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

    int consultaIdentificador() const;

    friend ostream& operator<<(ostream &os, const Parella &parella);

    friend istream& operator>>(istream &is, Parella &parella);
};