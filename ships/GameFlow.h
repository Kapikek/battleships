#pragma once
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Player.h"
#include "Computer.h"
#include "Ship.h"

class GameFlow
{
private:
	vector<Player*>players;


public:
	GameFlow();
	void Intro();
	void Shoot(Player* shooter, Player* victim);

};

