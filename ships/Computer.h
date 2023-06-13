#pragma once
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Player.h"
#include <cstdlib>


class Computer : public Player
{
	using Player::Player;
private:
	bool isreal = 0;

public:
	void AddShips();

};

