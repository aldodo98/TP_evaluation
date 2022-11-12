#pragma once
#include<vector>
class Label
{
	float distance;
	float duree;
	std::vector<int> chemin;
public:
	Label();
	Label(float, float);
	void set_distance(float);
	float get_distance();
	void set_duree(float);
	float get_duree();

};