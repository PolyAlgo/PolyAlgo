//Auteur:   Rémi Pelletier
//Fichier:  Multiples-RemiPelletier.cpp
//Problème: Multiples (Compétition informatique CEGInfo-CEGL 2016)
//Score:    50/50

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long parseChaineChar(string chaineNombre, int base)
{
	long long decimal = 0;
	int puissance = 0;
	for (unsigned int i = 0; i < chaineNombre.length(); ++i) {
		if (chaineNombre[chaineNombre.length() - 1 - i] == ')') {
			decimal += stoi(chaineNombre.substr(chaineNombre.length() - 3 - i, 2)) *
				(long long)pow((long double)base, (long double)puissance);
			i += 3;
		}
		else {
			decimal += (chaineNombre[chaineNombre.length() - 1 - i] - '0') *
				(long long)pow((long double)base, (long double)puissance);
		}
		++puissance;
	}
	return decimal;
}


int maxPuissance(long long nombre, int base)
{
	int puissance = 0;
	while (nombre / (long long)pow((long double)base, (long double)puissance++) > 1) {}
	return --puissance;
}


string nombreVersChaine(long long nombre, int base)
{
	string chaine = "";
	for (int i = maxPuissance(nombre, base); i >= 0; --i) {
		long long valPuissance = (long long)pow((long double)base, (long double)i);
		int facteur = (int)(nombre / valPuissance);
		string chaineFacteur = to_string(facteur);
		if (facteur >= 10) {
			chaineFacteur.insert(0, 1, '(');
			chaineFacteur.push_back(')');
		}
		chaine.append(chaineFacteur);
		nombre %= valPuissance;
	}

	return chaine;
}


string formatterChaine(const string& chaine, int largeur)
{
	string nouvelleChaine = "";
	int nChiffres = 0;
	for (int i = chaine.length() - 1; i >= 0 && nChiffres < largeur; --i) {
		if (chaine[i] == ')') {
			nouvelleChaine.insert(0, chaine.substr(i - 3, 4));
			i -= 3;
		}
		else {
			nouvelleChaine.insert(0, 1, chaine[i]);
		}
		++nChiffres;
	}

	return string(largeur - nChiffres, '0') + nouvelleChaine + "\n";
}


int main()
{
	string chaineNombrePremier;
	long long nombrePremier;
	int base, nChiffres, nMultiples;

	cin >> chaineNombrePremier >> base >> nChiffres >> nMultiples;
	nombrePremier = parseChaineChar(chaineNombrePremier, base);

	string output = "";
	for (int i = 0; i < nMultiples; ++i) {
		string chaineNombre;
		cin >> chaineNombre;
		long long nombre = parseChaineChar(chaineNombre, base);
		long long facteur = nombre / nombrePremier;
		output += formatterChaine(nombreVersChaine(facteur, base), nChiffres);
	}

	cout << output;

	return 0;
}
