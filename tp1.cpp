// tp1_lacomme.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<vector>
#include <fstream>
#include "Label.h"
#include "Sommet.h"
using namespace std;

static int a;
const int NMAX = 300;
const int MMAX = 1000;

typedef struct Node {
	int nb_Node[NMAX];
	int x[NMAX];
	int y[NMAX];
	int succ[NMAX][10];
}Node;


typedef struct Arcs {
	int arc[MMAX];
	int from[MMAX];
	int to[MMAX];
	float longueur[MMAX];
	float duree[MMAX];
}Arcs;


void Lecteur(string nom, Node& node, Arcs& arcs) {
	ifstream infile;
	string vide;
	string Name;
	int Nodes;
	string Coords;
	int Arcs;
	infile.open(nom);
	infile >> vide >> vide >> Name;
	infile >> vide >> vide >> Nodes;
	infile >> vide >> vide >> Coords;
	infile >> vide >> vide >> Arcs;
	infile >> vide >> vide >> vide;
	infile >> vide >> vide >> vide;
	for (int i = 1; i <= Nodes; i++) {
		infile >> vide >> vide >> node.nb_Node[i];
		infile >> vide >> vide >> vide >> node.x[i];
		infile >> vide >> vide >> vide >> node.y[i];
		infile >> vide >> vide >> vide;
		for (int j = 1; j < 10; j++) {
			infile >> node.succ[i][j];
			infile >> vide;
			if (vide == ",")
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	infile >> vide >> vide >> vide >> vide;
	for (int i = 1; i <= Arcs; i++) {
		infile >> vide >> vide >> arcs.arc[i];
		infile >> vide >> vide >> vide >> arcs.from[i];
		infile >> vide >> vide >> vide >> arcs.to[i];
		infile >> vide >> vide >> vide >> arcs.longueur[i];
		infile >> vide >> vide >> vide >> arcs.duree[i] >> vide;
	}
	//cout << node.succ[210][2] << endl;
	cout << arcs.duree[2] << endl;
	infile.close();

}

bool inserer(Label& l,Sommet& s) {
	Sommet::iterator it = s.begin();
	//std::vector<Label> v1;
	unsigned i = 0;
	while (it != s.end())
	{
		bool ajoute = false;
		if (l.get_distance()<(*it)->get_distance())
		{
			if (l.get_duree()<=(*it)->get_duree())
			{
				s.v.erase(it);
				ajoute = true;
			}
			else
			{
				ajoute = true;
			}
		}
		else
		{
			if (l.get_duree()<(*it)->get_duree())
			{
				ajoute = true;
			}
			else
			{
				ajoute = false;
				break;
			}
		}
		if (ajoute)
		{
			s.v.push_back(&l);
		}
	}

}
int main()
{
	Node mon_node;
	Arcs mon_arcs;
	Lecteur("DLP_210.dat", mon_node, mon_arcs);
	//initialise
	Label L0;
	Sommet s;
	s.v.push_back(&L0);//empiler
	if (s.v.size()>0)
	{
		//取出pile里面的sommet，depiler。需要一个list里面装label，每次depiler之后保留的路径都需要再次分解
		//x = 
	}

	std::cout << "Hello World!\n";
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
