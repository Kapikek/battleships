#pragma once
#include "Player.h"
#include <cstdlib>


class Computer : public Player
{
	using Player::Player;
	bool isreal = 0;

public:
	void AddShips();


};

