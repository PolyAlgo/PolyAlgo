//-----------------------------------------------------------------------------
//     Fichier : Mushroom Monster - Antoine Boisier-Michaud.cpp
//      Auteur : Antoine Boisier-Michaud
//        Date : 2016-02-11
// Description : Ma solution pour le challenge Mushroom Monster du round 1 de la
//               compétition Google Code Jam 2015 (http://bit.ly/1WgWPPL).
//               Cette solution résout tous les testcases.
//-----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> readMushrooms(ifstream& data)
{
	int n;
	data >> n;
	vector<int>	mushrooms;

	for (int j = 0; j < n; ++j)
	{
		int nMushrooms;
		data >> nMushrooms;
		mushrooms.push_back(nMushrooms);
	}

	return mushrooms;
}

int main()
{
	ifstream data("test"); 
	int nTestcases;
	data >> nTestcases;

	for (int i = 1; i <= nTestcases; ++i)
	{
		int test1 = 0, test2 = 0, deltaMax = 0;
		vector<int> mushrooms = readMushrooms(data);

		// Test 1
		for (unsigned int j = 0; j < mushrooms.size() - 1; ++j)
		{
			int delta = max(0, mushrooms[j] - mushrooms[j + 1]);
			test1 += delta;
			deltaMax = max(deltaMax, delta); // Calcule le delta max pour le test 2, évite d'utiliser une boucle de plus
		}

		// Test 2
		for (unsigned int j = 0; j < mushrooms.size() - 1; ++j)
		{
			test2 += min(mushrooms[j], deltaMax);
		}

		cout << "Case #" << i << ": " << test1 << " " << test2 << endl;
	}

}