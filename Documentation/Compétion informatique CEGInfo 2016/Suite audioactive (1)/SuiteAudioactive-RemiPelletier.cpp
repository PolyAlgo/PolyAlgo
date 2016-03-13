//Auteur:   Rémi Pelletier
//Fichier:  SuiteAudioactive-RemiPelletier.cpp
//Problème: Suite audioactive (Compétition informatique CEGInfo-CEGL 2016)
//Score:    25/25

#include <cmath>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string nombre;
	cin >> nombre;

	if (nombre.length() % 2 != 0) {
		cout << nombre;
	}
	else {

		bool estFini = false;
		while (!estFini) {
			string copy = "";
			char lastChar = '\0';
			for (int i = 0; i < nombre.length() / 2 && !estFini; ++i) {
				copy += string(nombre[i * 2] - '0', nombre[i * 2 + 1]);
				estFini = lastChar == nombre[i * 2 + 1];
				lastChar = nombre[i * 2 + 1];
			}
			estFini |= copy.length() % 2 != 0;
			if (estFini) {
				cout << nombre;
			}
			else if (nombre.compare(copy) == 0) {
				cout << ":(";
				estFini = true;
			}
			else {
				nombre = copy;
			}
		}
	}

	return 0;
}
