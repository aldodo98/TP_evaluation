// tp1_lacomme.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<vector>
#include <fstream>
#include "Label.h"
#include "Sommet.h"
#include "Pile.h"

using namespace std;
static int a;
const int NMAX = 300;
const int MMAX = 1000;

typedef struct Node {
	int nb_node;
	int nb_arcs;
	int nb_Node[NMAX];
	int nb_succ_chaque_sommet[NMAX] = { 0 };
	int x[NMAX];
	int y[NMAX];
	int succ[NMAX][10];
}Node;

typedef struct arcs {
	float longueur;
	float duree;
};
typedef struct Arcs {
	int arc[MMAX];
	int from[MMAX];
	int to[MMAX];
	float longueur[MMAX];
	float duree[MMAX];
	arcs arcs[NMAX][NMAX];
}Arcs;



void Lecteur(string nom, Node& node, Arcs& arcs) {
	ifstream infile;
	string vide;
	string Name;
	int Nodes;
	string Coords;
	int Arcs;
	int nb_succ_chaque_sommet[NMAX] = { 0 };
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
		for (int j = 1; j < 100; j++) {
			infile >> node.succ[i][j];
			infile >> vide;
			node.nb_succ_chaque_sommet[i] += 1;

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
		float duree = 0;
		infile >> vide >> vide >> vide >> duree >> vide;
		arcs.duree[i] = duree * abs(arcs.from[i] - arcs.to[i]);
	}
	int n = 1;
	for (int i = 1; i < Arcs + 1; i++)
	{
		arcs.arcs[arcs.from[i]][arcs.to[i]].longueur = arcs.longueur[i];
		//arcs.arcs[arcs.from[i]][arcs.to[i]].duree = arcs.duree[i]* abs(arcs.from[i] - arcs.to[i]);
		arcs.arcs[arcs.from[i]][arcs.to[i]].duree = arcs.duree[i];

	}
	//cout << arcs.arcs[2][3].longueur << endl;
	node.nb_node = Nodes;
	node.nb_arcs = Arcs;
	infile.close();

}

bool inserer(Label& l, vector<pair<float, float>>& s, int k) {

	//std::vector<Label> v1;
	unsigned i = 0;
	bool ajoute = true;

	for (int i = 0; i < s.size(); i++)
	{
		if (l.get_distance() < s[i].first)
		{
			if (l.get_duree() < s[i].second)
			{
				s.erase(s.begin() + i);
				//ajoute = true;
			}
			else
			{
				//ajoute = true;
			}
		}
		else
		{
			if (l.get_duree() < s[i].second)
			{
				//ajoute = true;
			}
			else
			{
				ajoute = false;

			}
		}
	}
	if (s.size() <= 0)
	{
		ajoute = true;
	}
	if (ajoute)
	{
		pair<float, float> p(l.get_distance(), l.get_duree());
		s.push_back(p);
	}
	return ajoute;

}
//sommet里面有到路径
//generer new label
void generer_new_label(Node& node, Arcs& arcs, vector<pair<float, float>>& l, int o, int s, Label& l1, int nb_succ) {
	float distance;
	float duree;
	int size = l.size();

	if (l.size() <= 0)
	{
		distance = arcs.arcs[o][s].longueur;
		duree = arcs.arcs[o][s].duree;
	}
	else
	{
		distance = l[nb_succ].first + arcs.arcs[o][s].longueur;
		duree = l[nb_succ].second + arcs.arcs[o][s].duree;
	}

	l1.set_distance(distance);
	l1.set_duree(duree);
}

int main()
{
	Node mon_node;
	Arcs mon_arcs;
	Lecteur("DLP_210.dat", mon_node, mon_arcs);
	//mon_arcs.duree[1] = mon_arcs.duree[1] * abs();

	//initialise
	Label L0;
	Sommet s0;
	vector<int> pile;
	int nn = mon_node.nb_node + 1;
	vector<vector<pair<float, float>>> l_list(nn);

	pile.push_back(1);//将原点s0注入到pile里面
	/*
	cout << mon_node.succ[2][1] << endl;
	cout << l_list[6].size() << endl;

	for (auto i:l_list[1])
	{
		cout << i.first << endl;

	}
	*/
	int numbre = 0;
	while (pile.size() > 0)
	{
		int x = pile.back();
		pile.pop_back();
		for (int i = 1; i <= mon_node.nb_succ_chaque_sommet[x]; i++)
		{
			int j = 0;
			do
			{
				int sommet_succ = mon_node.succ[x][i];
				//pile中导出的坐标已知，现在求该点到其子坐标的值,需要先得知该坐标保存的路径
				Label l1;
				generer_new_label(mon_node, mon_arcs, l_list[x], x, sommet_succ, l1, j);
				bool si_insere = inserer(l1, l_list[sommet_succ], sommet_succ);
				//需要判断是不是dominer，如果非dominer，则加入pile，如果不是则不加入
				//inserer之前要生成label和sommet
				if (si_insere)
				{
					pile.push_back(mon_node.succ[x][i]);
				}
				j++;
			} while (j < l_list[x].size());
		}
		if (x == 210)
		{
			numbre++;

		}
	}
	cout << numbre << endl;
	
	for (auto i : l_list[210])
	{
		cout << i.first << ", " << i.second << endl;
	}
	//s0.v.push_back(&L0);
	/*
	if (pile.p.size() > 0)
	{
		Pile::iterator p_iterator = pile.begin();
		p_iterator = pile.begin(); //将pile里面的第一个sommet取出来，准备遍历
		Sommet s_ite;
		Sommet::iterator it_label = s_ite.begin();
		//第一个循环，取出pile里面的sommet，然后获取下一个sommet的信息
		while (true)
		{
			while (p_iterator != pile.end())
			{
				s_ite = *(*p_iterator);
				int x = s_ite.numero;
				int nb_succ = mon_node.nb_succ_chaque_sommet[x];
				for (int j = 1; j <= nb_succ; j++)
				{
					//cout << mon_node.succ[x][j] << endl;
					int n_sommet_succ = mon_node.succ[x][j]; //得到该sommet的子sommet,接下来要求子sommet里面有多少个label

					for (int k = 0; k <= s_ite.v.size(); k++)
					{
						s_ite.v[k] =
					}
				}
				while (it_label != s_ite.end()) {
					Label L;
					L = *(*it_label);
					it_label++;
				}
				p_iterator++;
			}
			//quand le pile est vide
			break;
		}
		for (int i = 1; i < mon_node.nb_node; i++)
		{

		}




			//取出pile里面的sommet，depiler。需要一个list里面装label，每次depiler之后保留的路径都需要再次分解
			//x =


	};
	*/
	std::cout << "Hello the end!\n";
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
