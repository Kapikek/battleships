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

void Player::AddShips() {

	for (int i = 0; i < 5; i++) {

		Ship* s1 = new Ship(i);

		CheckForConflicts(s1, i);
		//todo sprawdzenie czy nie ma konfliktow

		ships.push_back(s1);
	}



}

void Player::CheckForConflicts(Ship* s, int k) {

	for (int i = s->x; i <= s->x + (abs(~(s->type)) * s->sizes[k]); i++) {

		for (int j = s->y; i <= s->y + (s->type * s->sizes[k]); j++) {



		}

	}



}