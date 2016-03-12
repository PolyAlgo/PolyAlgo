//Auteur:   Rémi Pelletier
//Fichier:  PolyPlacement-RemiPelletier.cpp
//Problème: PolyPlacement (Compétition informatique CEGInfo-CEGL 2016)
//Score:    100/100

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


struct Placement
{
	int    start = 0;
	int    end = 0;
	double value = 0.0;
};


bool sortPlacement(const Placement& placement1, const Placement& placement2)
{
	return placement1.end < placement2.end;
}


double computeBestPlacementValue(vector<Placement>& placements)
{
	sort(placements.begin(), placements.end(), sortPlacement);

	vector<double> bestPlacements(placements.size() + 1, 0);

	for (int i = 0; i < placements.size(); ++i) {
		double option1 = bestPlacements[i];
		int left = 0, right = i;

		while (left <= right) {
			int mid = (int)(ceil((left + right) / 2.0));
			if (placements[mid].end <= placements[i].start) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		double option2 = bestPlacements[left] + placements[i].value;
		bestPlacements[i + 1] = max(option1, option2);
	}

	return bestPlacements.back();
}


int main()
{
	int nCases;
	cin >> nCases;

	for (int i = 0; i < nCases; ++i) {
		bool reckless;
		int nPlacements, nDays;
		vector<Placement> placements;

		cin >> nPlacements >> reckless >> nDays;
		cin.ignore(100, '\n');

		for (int j = 0; j < nPlacements; ++j) {
			string line;
			getline(cin, line);
			stringstream inputLine(line);

			Placement curPlacement;
			inputLine >> curPlacement.start >> curPlacement.end;

			while (inputLine.peek() != EOF) {
				double risk, profit;
				inputLine >> risk >> profit;
				if (reckless) {
					curPlacement.value = max(curPlacement.value, profit);
				}
				else {
					curPlacement.value += risk * profit;
				}
				inputLine.ignore(1);
			}

			placements.push_back(curPlacement);
		}

		cout << fixed << setprecision(2) << round(computeBestPlacementValue(placements) * 100.0) / 100.0 << endl;
	}

	return 0;
}
