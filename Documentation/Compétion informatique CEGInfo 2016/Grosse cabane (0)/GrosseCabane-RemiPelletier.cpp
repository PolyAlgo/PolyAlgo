//Auteur:   Rémi Pelletier
//Fichier:  GrosseCabane-RemiPelletier.cpp
//Problème: Grosse cabane (Compétition informatique CEGInfo-CEGL 2016)
//Score:    50/50

#include <cmath>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void spread(vector<string>& tableau, int rangee, int colonne)
{
	tableau[rangee][colonne] = 'x';
	if ((rangee - 1) >= 0 && tableau[rangee - 1][colonne] == 'o') {
		spread(tableau, rangee - 1, colonne);
	}
	if ((rangee + 1) < tableau.size() && tableau[rangee + 1][colonne] == 'o') {
		spread(tableau, rangee + 1, colonne);
	}
	if ((colonne - 1) >= 0 && tableau[rangee][colonne - 1] == 'o') {
		spread(tableau, rangee, colonne - 1);
	}
	if ((colonne + 1) < tableau[rangee].length() && tableau[rangee][colonne + 1] == 'o') {
		spread(tableau, rangee, colonne + 1);
	}
}


int main()
{
	int nRangees, nColonnes, nPieces = 0;
	cin >> nRangees >> nColonnes;
	vector<string> tableau;
	for (int i = 0; i < nRangees; ++i) {
		string rangee;
		cin >> rangee;
		tableau.push_back(rangee);
	}

	for (int i = 0; i < nRangees; ++i) {
		for (int j = 0; j < nColonnes; ++j) {
			if (tableau[i][j] == 'o') {
				spread(tableau, i, j);
				++nPieces;
			}
		}
	}

	cout << nPieces;

	return 0;
}
