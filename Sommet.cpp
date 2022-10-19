#include "Sommet.h"

Sommet::Sommet() {
	nb_l = 0;
	numero = 0;
}
Sommet::Sommet(int n) {
	nb_l = 0;
	numero = n;
}

void Sommet::ajouter(Label& l) {
	nb_l++;
	v.push_back(&l);
}


std::vector<Label*>::iterator Sommet::begin() {
	return v.begin();
}
std::vector<Label*>::iterator Sommet::end() {
	return v.end();
}
