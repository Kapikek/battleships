#pragma once
#include <iostream>
#include <vector>
#include "Ship.h"

using namespace std;

class Player
{
	friend class GameFlow;
private:
	int const grid_size = 10;
	int** grid;
	vector<Ship*>ships;
	string name;


public:

	Player(string Name);
	~Player();

	void PrintGrid(); //todo
	void AddShips();
	void CheckForConflicts(Ship* s, int k);
};

