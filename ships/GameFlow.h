#pragma once
#include "Player.h"
#include "Computer.h"

class GameFlow
{
private:
	vector<Player*>players;


public:
	GameFlow();
	void Intro();
	void GameLoop(Player* P1,Player* P2);

};

