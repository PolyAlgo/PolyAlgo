//Auteur:   Rémi Pelletier
//Fichier:  TropLongTropCher-RemiPelletier.cpp
//Problème: Trop long, trop cher (Compétition informatique CEGInfo-CEGL 2016)
//Score:    37.5/50 (les 2 derniers tests échouent en raison d'un timeout)

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;


struct Edge
{
	int id1;
	int id2;
	int length;
};


struct Node
{
	int id;
	vector<Edge> edges;
};


bool equals(const Edge& edge1, const Edge& edge2)
{
	return (edge1.id1 == edge2.id1 && edge1.id2 == edge2.id2) ||
		   (edge1.id1 == edge2.id2 && edge1.id2 == edge2.id1);
}


void addEdgeNoRepCheck(vector<Edge>& edges, const Edge& edge)
{
	int j = 0;
	bool done = false;
	for (int i = 0; i < edges.size() && !done; ++i) {
		if (edge.length < edges[i].length) {
			edges.insert(edges.begin() + i, edge);
			done = true;
		}
	}
	if (!done) {
		edges.push_back(edge);
	}
}


void addNodeEdgesRemoveReps(vector<Edge>& edges, const Node& node)
{
	int j = 0;
	bool done = false;
	for (int i = 0; i < edges.size() && !done; ++i) {
		if (equals(node.edges[j], edges[i])) {
			if (edges.size() > 1) {
				edges.erase(edges.begin() + i);
			}
			++j;
			--i;
		}
		else if (node.edges[j].length < edges[i].length) {
			edges.insert(edges.begin() + i, node.edges[j++]);
		}
		done = j == node.edges.size();
	}
	if (!done) {
		edges.insert(edges.end(), node.edges.begin() + j, node.edges.end());
	}
}


void removeEdge(vector<Edge>& edges, const Edge& edge)
{
	for (int i = 0; i < edges.size(); ++i) {
		if (equals(edge, edges[i]) && edges.size() > 1) {
			edges.erase(edges.begin() + i);
			break;
		}
	}
}


bool sortEdges(const Edge& edge1, const Edge& edge2)
{
	int e1id1 = min(edge1.id1, edge1.id2);
	int e1id2 = max(edge1.id1, edge1.id2);
	int e2id1 = min(edge2.id1, edge2.id2);
	int e2id2 = max(edge2.id1, edge2.id2);
	return (e1id1 == e2id1) ? e1id2 < e2id2 : e1id1 < e2id1;
}


int main()
{
	int nNodes;
	cin >> nNodes;
	vector<Node> nodes;

	for (int i = 0; i < nNodes; ++i) {
		Node curNode;
		curNode.id = i;
		for (int j = 0; j < nNodes; ++j) {
			string distance;
			cin >> distance;
			if (distance.compare("-") != 0) {
				Edge lien = { i, j, stoi(distance) };
				addEdgeNoRepCheck(curNode.edges, lien);
			}
		}
		nodes.push_back(curNode);
	}

	vector<Node> linkedNodes;
	vector<Edge> usedEdges;
	vector<Edge> availableEdges;

	linkedNodes.push_back(nodes[0]);
	availableEdges.insert(availableEdges.end(), nodes[0].edges.begin(), nodes[0].edges.end());

	bool done = false;
	while (!done) {
		Edge nextEdge = availableEdges.front();
		usedEdges.push_back(nextEdge);
		Node newNode = nodes[nextEdge.id2];
		linkedNodes.push_back(newNode);
		done = linkedNodes.size() == nNodes;
		if (!done) {
			addNodeEdgesRemoveReps(availableEdges, newNode);
		}
	}

	sort(usedEdges.begin(), usedEdges.end(), sortEdges);

	for (int i = 0; i < usedEdges.size(); ++i) {
		cout << min(usedEdges[i].id1, usedEdges[i].id2) + 1 << " " << max(usedEdges[i].id1, usedEdges[i].id2) + 1 << endl;
	}

	return 0;
}
