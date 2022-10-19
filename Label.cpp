#include "Label.h"


Label::Label() {
	distance = 999;
	duree = 999;
	chemin.push_back(0);
}
Label::Label(int a,int b,int c) {
	distance = a;
	duree = b;
	chemin.push_back(c);
}

void Label::set_distance(int d) {
	distance = d;
}
int Label::get_distance() {
	return distance;
}
void Label::set_duree(int d) {
	duree = d;
}
int Label::get_duree() {
	return duree;
}
