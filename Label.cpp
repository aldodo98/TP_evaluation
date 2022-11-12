#include "Label.h"


Label::Label() {
	distance = 999;
	duree = 999;
	chemin.push_back(0);
}
Label::Label(float a, float b) {
	distance = a;
	duree = b;
	//chemin.push_back(c);
}

void Label::set_distance(float d) {
	distance = d;
}
float Label::get_distance() {
	return distance;
}
void Label::set_duree(float d) {
	duree = d;
}
float Label::get_duree() {
	return duree;
}
