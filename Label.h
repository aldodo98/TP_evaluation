#pragma once
#include<vector>
class Label
{
	int distance;
	int duree;
	std::vector<int> chemin;
public:
	Label();
	Label(int,int);
	void set_distance(int);
	int get_distance();
	void set_duree(int);
	int get_duree();

};