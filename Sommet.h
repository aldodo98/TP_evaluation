#pragma once
#ifndef SOMMET_TP1_HPP
#define SOMMET_TP1_HPP

#include<vector>
#include "Label.h"
#include <iterator>
class Sommet
{
	int nb_l;
	
public:
	std::vector<Label*> v;
	int numero;
public:
	Sommet();
	Sommet(int);
	using iterator = std::vector<Label*>::iterator;
	std::vector<Label*>::iterator begin();
	std::vector<Label*>::iterator end();
	void ajouter(Label&);
	//void supprimer();

};

#endif