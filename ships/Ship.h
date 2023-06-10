#pragma once
#include <string>
#include <iostream>

using namespace std;

class Ship
{
	friend class Player;
private:
	
	int sizes[5] = {5, 4, 3, 3, 2};
	std::string colors[5] = { //\033[0m - reverse
		"\033[1;31m", //red
		"\033[1;33m", //yellow
		"\033[1;32m", //green
		"\033[1;32m",
		"\033[1;34m"  //blue
		};
	int x, y; //x being letters from a to j (columns), and y being numbers 1 to 10 (rows)
			  //but represented by numbers 0 - 9
	bool type; //0 - vertical, 1 - horizontal


public:

	Ship(int i);
	string GetCoords();


};

