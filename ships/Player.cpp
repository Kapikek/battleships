#include "Player.h"

Player::Player(string Name) {

	name = Name;
	
	grid = new int* [grid_size];

	for (int j = 0; j < grid_size; j++) {
		grid[j] = new int[grid_size];
		for (int i = 0; i < grid_size; i++)
			grid[j][i] = 0;
	}
	

}

Player::~Player() {
	cout << "deleting players grid\n";
	
	for (int j = 0; j < grid_size; j++)
		delete grid[j];
	delete grid;

	for (auto t : ships)
		delete t;
	

}

void Player::PrintGrid() {





}