#pragma once
#include "Sommet.h"
class Pile
{
public:
	std::vector<Sommet*> p;
	using iterator = std::vector<Sommet*>::iterator;
	std::vector<Sommet*>::iterator begin();
	std::vector<Sommet*>::iterator end();
};

