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

	void PrintGrid(); //todo
	Player(string Name);
	~Player();




};

