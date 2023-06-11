#pragma once

#include <vector>
#include "Ship.h"

using namespace std;

class Player
{
	friend class GameFlow;
private:
	int const grid_size = 10;
	int const num_of_ships = 5;
	int** grid;
	vector<Ship*>ships; 
	string name;


public:

	Player(string Name);
	~Player();

	void PrintGrid(bool IsEnemy); 
	void AddShips();
	void GridAdd(Ship* s, int k); 
	bool CheckForConflicts(Ship* s, int k); //return 1 for conflicts
	//todo GridClear(); if someone want to rearrange their ships
	int HowManyLeft();

};

