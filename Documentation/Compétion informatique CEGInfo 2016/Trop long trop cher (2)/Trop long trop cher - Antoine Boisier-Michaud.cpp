//-----------------------------------------------------------------------------
//     Fichier : Trop long trop cher - Antoine Boisier-Michaud.cpp
//      Auteur : Antoine Boisier-Michaud
//        Date : 2016-01-27
// Description : Ma solution pour le problème "Trop long trop cher" lors de la 
//		         compétition informatique CEGInfo - CEGL 2016. (http://bit.ly/1SiwDnZ)
//               Cette solution réussit les 7 premiers testcases (et en échoue un).
//-----------------------------------------------------------------------------


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

struct edge
{
	int a;
	int b;
	long long cost;
};

long long    n;				 // Nombre de noeuds
vector<edge> availableEdges; // J'aurais pu utiliser une pile.
vector<edge> path;			 // Idem
bool*        visitedNodes;
long long    nbVisitedNodes = 0;

void read()
{
	cin >> n;

	visitedNodes = new bool[n];

	for (int i = 0; i < n; ++i)
	{
		visitedNodes[i] = false; // Le noeud n'est pas visité.

		for (int j = 0; j < n; ++j) // On aurait pu commencer j à i mais ça cassait tout
		{
			string str;
			cin >> str;
			if (str != "-")
			{
				edge e;
				e.cost = atoi(str.c_str());

				e.a = min(i, j);
				e.b = max(i, j);

				availableEdges.push_back(e);
			}
		}
	}

	// Très important, on classe les noeuds en fonction de leur coût (croissant).
	sort(availableEdges.begin(), availableEdges.end(),
		[](const edge & a, const edge & b) -> bool
	{
		return a.cost < b.cost;
	});
}

void findPath()
{
	path.push_back(availableEdges[0]);
	visitedNodes[availableEdges[0].a] = true;
	visitedNodes[availableEdges[0].b] = true;

	for (int i = 1; i < availableEdges.size() && nbVisitedNodes < n; ++i)
	{
		// Si le lien ne relie pas deux noeuds déjà visités
		if (visitedNodes[availableEdges[i].a] ^ visitedNodes[availableEdges[i].b])
		{
			++nbVisitedNodes;
			visitedNodes[availableEdges[i].a] = true;
			visitedNodes[availableEdges[i].b] = true;
			path.push_back(availableEdges[i]);
			i = 1; // Je ne me souviens plus pourquoi on revient au début mais ça fonctionne...
		}
	}
}

int main()
{
	read();

	findPath();

	sort(path.begin(), path.end(),
		[](const edge & a, const edge & b) -> bool
	{
		return a.a < b.a || (a.a == b.a && a.b < b.b);
	});

	for (int i = 0; i < path.size(); ++i)
		cout << (path[i].a + 1) << " " << (path[i].b + 1) << endl; 

	return 0;
}

