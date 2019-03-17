#include <iostream>
#include <vector>
#include "Comparsa.h"

using namespace std;

void creaComparses(vector<Comparsa> &comparses) {
  /* Pre: comparses es un vector de Comparsa */
  /* Post: El vector comparses conté les comparses entrades per l'usuari */
  int n;
  cin >> n;
  comparses.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> comparses[i];
  }
}

void mostrarComparsa(const vector<Comparsa> &comparses) {
  /* Pre: Vector amb les comparses */
  /* Post: Imprimeix pel canal estandar de sortida les dades de la comparsa si aquesta existeix */
  string sigles;
  unsigned int i = 0;
  bool trobat = false;
  cin >> sigles;

  while(not trobat and i < comparses.size()) {
    if (comparses[i].consultaSigles() == sigles) {
      cout << comparses[i] << endl;
      trobat = true;
    }
    ++i;
  }

  if (not trobat) cout << "No s'ha trobat la Comparsa " << sigles << endl;
}

bool comprovaParellaValida(const Parella &p, const Comparsa &comparsa) {
  /* Pre:   p es la Parella a introduir, no es vuida. Comparsa amb la comparsa desti*/
  /* Post:  Si la parella es valida per ser afegida, retorna true, sino false */
	bool valid = true;
    int j = 0;

    while (j < comparsa.consultanParelles() ) {
      	if (comparsa.existeixParella(p.consultaIdentificador())) {
        	valid = false;
	}
 	vector<Parella> parelles = comparsa.consultaParelles();

    	for (unsigned int i = 0; i < parelles.size(); ++i) {
    		vector< vector< string > > membres = parelles[i].consultaMembres();
    		if (membres[0][1] == p.consultaMembres()[0][1] 
    			or membres[0][1] == p.consultaMembres()[1][1]
    			or membres[1][1] == p.consultaMembres()[0][1] 
    			or membres[1][1] == p.consultaMembres()[1][1])
    			valid = false;
    	}
    	++j;
    }

	return valid;
}

void afegirParella(vector<Comparsa> &comparses) {
  /* Pre: Vector amb les comparses */
  /* Post: Nova parella afegida a la comparsa */
  string sigles;
  unsigned int i = 0;
  bool trobat = false;
  cin >> sigles;

  while(not trobat and i < comparses.size()) {
    if (comparses[i].consultaSigles() == sigles) {
      trobat = true;
    } else {
      ++i;
    }
  }

  Parella p;
  cin >> p;

  if (not trobat) cout << "No s'ha trobat la Comparsa " << sigles << endl;
  else {

  	bool parellaValida = comprovaParellaValida(p, comparses[i]);
    if (not parellaValida)
      cout << "Aquesta Parella no es pot afegir " << sigles << endl;
    else {
      comparses[i].afegeixParella(p);
      cout << "Parella " << p << endl;
      cout << " afegida a : " << sigles << endl;
    }
  }
}

void mostrarTotesComparses(const vector<Comparsa> &comparses) {
  /* Pre: vector amb les comparses */
  /* Post: imprimeix pel canal estandar de sortida les dades de totes les comparses */
  cout << "Llistat de Comparsas: \n" << endl;
  for (unsigned int i = 0; i < comparses.size(); ++i) {
    cout << comparses[i] << endl;
  }
}

void canviarEcocaramel(vector<Comparsa> &comparses) {
  /* Pre: vector amb les comparses */
  /* Post: canvia el valor del ecocaramel de la comparsa introduida per l'usuari */
  string sigles;
  unsigned int i = 0;
  bool trobat = false;
  Comparsa comparsa;
  cin >> sigles;

  while(not trobat and i < comparses.size()) {
    if (comparses[i].consultaSigles() == sigles) {
      comparses[i].modificaCaramels(!comparses[i].consultaCaramels());
      cout << "Canviada la informació ecoCarament a la Comparsa : " << sigles << endl;
      trobat = true;
    }
    ++i;
  }

  if (not trobat) cout << "No s'ha trobat la Comparsa " << sigles << endl;
}

int main() {
    vector<Comparsa> comparses;
    int opcio;

    creaComparses(comparses);

    cin >> opcio;
    cout << "Opcio: " << opcio << endl;
    while (opcio != -5) {
      switch (opcio) {
        case -1:
          mostrarComparsa(comparses);
          break;
        case -2:
          afegirParella(comparses);
          break;
        case -3:
          mostrarTotesComparses(comparses);
          break;
        case -4:
          canviarEcocaramel(comparses);
          break;
        default:
          cout << "Opcio no implementada" << endl;
          break;
      }
      cin >> opcio;
      cout << "Opcio: " << opcio << endl;
    }
}
