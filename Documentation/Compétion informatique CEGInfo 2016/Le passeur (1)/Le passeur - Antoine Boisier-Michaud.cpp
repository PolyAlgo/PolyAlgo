 //-----------------------------------------------------------------------------
//     Fichier : Le passeur - Antoine Boisier-Michaud.cpp
//      Auteur : Antoine Boisier-Michaud
//        Date : 2016-01-27
// Description : Ma solution pour le problème "Le passeur" lors de la compéti-
//               tion informatique CEGInfo - CEGL 2016. (http://bit.ly/1OkjXfg)
//               Cette solution réussit les premiers testcases et timeout aux
//				 autres.
//-----------------------------------------------------------------------------

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>

using namespace std;

int found = 0; // Variable de controle, après n chemins trouvé, j'arrêtais la
               // recherche... oui c'est une mauvaise idée.

// Structures -----------------------------------------------------------------

// a et b ne peuvent pas être ensembles si x n'est pas là.
struct contrainte
{
	int a, b, x;
};

struct node
{
	unsigned int i = 0;			 // Index du noeud dans le graphe
	bool* config;				 // Configuration (0 = passé de l'autre côté)
	vector<unsigned int> liensA; // Liens allée
	vector<unsigned int> liensR; // Liens retour
};

struct nodes
{
	unsigned int nb = 0;
	vector<node> nds;
};

// Variables ------------------------------------------------------------------

int n, places; // n : nb de personnes	b : nb de places dans le bateau
unsigned int minimum;
vector<contrainte> contraintes;


// Prototypes -----------------------------------------------------------------

nodes generateValidConfigs();
nodes generateLinks();
void printNode(node n);
void read();
nodes generateLinks(nodes nds);
bool isNodeValid(node nd);
bool isLinkValid(nodes nds, unsigned int a, unsigned int b);
unsigned int findPath(nodes nds, unsigned int current,
	vector<unsigned int> visitedA,
	vector<unsigned int> visitedR,
	unsigned int moves);

// Main -----------------------------------------------------------------------
int main() {
	// Servira à accélérer l'algorithme. À chaque nouveau déplacement, on 
	// vérifiera si le nombre de déplacements effectués jusqu'à maintenant
	// est supérieur au nombre de déplacements de la meilleure solution trouvée.
	// Si oui, on arrête de chercher dans cette direction.
	minimum = (unsigned int)(-1);

	// On lit les entrées.
	read();

    // On génère les noeuds et les liens.
	nodes nds = generateLinks(generateValidConfigs()); 

	vector<unsigned int> vA, vB;

	// On cherche la solution.
	unsigned int sol = findPath(nds, 0, vA, vB, 1);

	if (sol == (unsigned int)(-1))
		cout << ":(";
	else
		cout << sol;

	return 0;
}

// Fonctions ------------------------------------------------------------------

// Cette fonction contient 6 returns différents, et est vraiment longue. Sorry 
unsigned int findPath(nodes nds, unsigned int current, 
                      vector<unsigned int> visitedA, 
	                  vector<unsigned int> visitedR, 
	                  unsigned int moves)
{
	// Si aucun lien ne mène au départ ou à l'arrivée on arrête tout de suite.
	if (nds.nds[nds.nb - 1].liensA.size() == 0 ||
		nds.nds[0].liensR.size() == 0)
		return (unsigned int)(-1);


	unsigned int minPath = (unsigned int)(-1);

	if (found < 10) // Tentative d'accélérer l'algorithme pas vraiment scientifique.
	{
		if (current == nds.nb - 1) // Si on est arrivé...
		{ 
			minimum = min(minimum, moves - 1);
			return moves - 1;
		}

		if (moves >= minimum) // Si le chemin actuel contient plus de mouvements que
			return minPath;   // le meilleur chemin déjà trouvé, on arrête.

		if (moves % 2 == 1)   // Contrôle les allées-retours
		{
			visitedA.push_back(current); // On ajoute le noeud à la liste de noeuds visités

			for (unsigned int i = 0; i < nds.nds[current].liensR.size(); ++i)
			{
				// Si ce noeud n'a pas déjà été visité
				if (find(visitedR.begin(), visitedR.end(), nds.nds[current].liensR[i]) == visitedR.end()) 
				{
					unsigned int path = findPath(nds, nds.nds[current].liensR[i], visitedA, visitedR, moves + 1);
					minPath = path < minPath ? path : minPath;
				}
			}
		}

		else
		{
			visitedR.push_back(current); // On ajoute le noeud à la liste de noeuds visités

			for (unsigned int i = 0; i < nds.nds[current].liensA.size(); ++i)
			{
				// Si ce noeud n'a pas déjà été visité
				if (find(visitedA.begin(), visitedA.end(), nds.nds[current].liensA[i]) == visitedA.end())
				{
					unsigned int path = findPath(nds, nds.nds[current].liensA[i], visitedA, visitedR, moves + 1);
					minPath = path < minPath ? path : minPath;
				}
			}
		}
	}

	return minPath;
}

nodes generateLinks(nodes nds)
{
	for (unsigned int i = 0; i < nds.nds.size(); ++i)
	{
		for (unsigned int j = i; j < nds.nds.size(); ++j) // On ne commence pas à 0 car
		{                                                 // les liens sont réciproques
			if (isLinkValid(nds, i, j))
			{
				nds.nds[i].liensR.push_back(j);
				nds.nds[j].liensA.push_back(i);
			}
		}
	}

	return nds;
}

// Si le nombre de passagers est inférieur au nombre de places dans le beateau
// et que le déplacement n'a lieu que dans un sens, le lien est valide.
bool isLinkValid(nodes nds, unsigned int a, unsigned int b)
{
	unsigned allees = 0, retours = 0;

	if (a == b)
		return false;

	for (int i = 0; i < n; ++i)
	{
		if ((int)nds.nds[a].config[i] - (int)nds.nds[b].config[i] > 0)
			++allees;
		else if ((int)nds.nds[a].config[i] - (int)nds.nds[b].config[i] < 0)
			++retours;
	}

	return (retours <= places && allees  == 0) ||
		   (allees  <= places && retours == 0);
}

nodes generateValidConfigs()
{
	nodes nds;

	for (unsigned int i = 0; i < pow(2, n); ++i)
	{
		node nd;

		nd.config = new bool[n]; // Ne pas oublier de libérer la mémoire. (évidemment j'ai oublié)

		for (int j = 0; j < n; ++j)
			nd.config[n - j - 1] = (i / (int)pow(2, j)) % 2; 

		if (isNodeValid(nd))
		{
			nd.i = nds.nb++;
			nds.nds.push_back(nd);
		}
	}

	return nds;
}

// Si le node respecte les contraintes
bool isNodeValid(node nd)
{
	if (contraintes.size() > 0)
	{
		for (unsigned int i = 0; i < contraintes.size(); ++i)
			if (nd.config[contraintes[i].a - 1] == nd.config[contraintes[i].b - 1] && nd.config[contraintes[i].a - 1] != nd.config[contraintes[i].x - 1])
				return false;
	}
	return true;
}

void read()
{
	cin >> n >> places;

	while (!cin.eof())
	{
		contrainte contr;
		cin >> contr.a >> contr.b >> contr.x;
		if (contr.a <= n && contr.b <= n && contr.x <= n)
			contraintes.push_back(contr);
	}
}