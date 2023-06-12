#pragma once
#include <string>
#include <iostream>

using namespace std;

class Ship
{
	friend class Player;
	friend class Gameflow;
private:
	
	int sizes[5] = {5, 4, 3, 3, 2};
	string colors[5] = { //\033[0m - reverse
		"\033[;31m", //red
		"\033[;33m", //yellow
		"\033[;32m", //green
		"\033[;32m",
		"\033[;34m"  //blue
		};
	int x, y; //x being letters from a to j (columns), and y being numbers 1 to 10 (rows)
			  //but represented by numbers 0 - 9
	bool type; //0 - vertical, 1 - horizontal


public:

	Ship(int i);
	Ship(int xx, int yy, bool typee);
	string GetCoords();


};

