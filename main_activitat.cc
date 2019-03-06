#include <iostream>
#include <vector>
#include "Comparsa.h"

using namespace std;

void creaComparses(vector<Comparsa> &comparses) {
  /* Pre: comparses es un vector de Comparsa */
  /* Post: el vector comparses conté les comparses entrades per l'usuari */
  int n;
  cin >> n;
  comparses.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> comparses[i];
  }
}

void mostrarComparsa(const vector<Comparsa> &comparses) {
  /* Pre: vector amb les comparses */
  /* Post: imprimeix pel canal estandar de sortida les dades de la comparsa */
  string sigles;
  unsigned int i = 0;
  bool trobat;
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

void afegirParella(vector<Comparsa> &comparses) {
  /* Pre: vector amb les comparses */
  /* Post: nova parella afegida a la comparsa */
  string sigles;
  unsigned int i = 0;
  bool trobat;
  cin >> sigles;

  while(not trobat and i < comparses.size()) {
    if (comparses[i].consultaSigles() == sigles) {
      trobat = true;
    }
    else {
      ++i;
    }
  }

  if (not trobat) cout << "No s'ha trobat la Comparsa " << sigles << endl;
  else {
    Parella p;
    cin >> p;
    comparses[i].afegeixParella(p);
  }
}

void mostrarTotesComparses(const vector<Comparsa> &comparses) {
  /* Pre: vector amb les comparses */
  /* Post: imprimeix pel canal estandar de sortida les dades de totes les comparses */
}

void mostrarEcocaramel(const vector<Comparsa> &comparses) {
  /* Pre: vector amb les comparses */
  /* Post: imprimeix pel canal estandar de sortida si la comparsa té ecocaramel */
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
          mostrarEcocaramel(comparses);
          break;
        default:
          cout << "Opcio no implementada" << endl;
          break;
      }
      cin >> opcio;
      cout << "Opcio: " << opcio << endl;
    }






}
