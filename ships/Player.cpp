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

void Player::PrintGrid(bool IsEnemy) {

	string alf = "ABCDEFGHIJ";
	cout << "\033[1;32m" << name << "'s board" << "\033[0m" << endl << endl;

	cout << "   A B C D E F G H I J" << endl;
	for (int i = 0; i < grid_size; i++) {
		cout << i + 1;
		if (i + 1 < 10)cout << " ";
		for (int j = 0; j < grid_size; j++) {

			if(IsEnemy == 0) switch (grid[i][j]) {
			case 0: cout << "\033[;36m " << "0" << "\033[0m";
				break;
			case 1: cout << "\033[;31m" << " 5" << "\033[0m";
				break;
			case 2: cout << "\033[;33m" << " 4" << "\033[0m";
				break;
			case 3: cout << "\033[;32m" << " 3" << "\033[0m";
				break;
			case 4: cout << "\033[;34m" << " 2" << "\033[0m";
				break;

			case -1: cout<<"\033[;35m"<<" X"<<"\033[0m";
			}
			if (IsEnemy == 1) switch (grid[i][j]) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 0: cout << "\033[1;36m " << "0" << "\033[0m";
				break;

			case -1: cout << "\033[1;35m" << " X" << "\033[0m";
			}

		}
		cout << endl;
	}

}

void Player::AddShips() {

	for (int i = 0; i < num_of_ships; i++) {

		PrintGrid(0);

		Ship* s1 = new Ship(i);
		

		bool conflict = CheckForConflicts(s1, i);
		if (conflict) {
			i--;
			cout << "Conflict emerged, try other positions" << endl;
			
		}
		else {
			ships.push_back(s1);
			GridAdd(s1, i);
		}

	}



}

bool Player::CheckForConflicts(Ship* s, int k) {
	//return 1 for conflicts
	//type  =  0 - vertical, 1 - horizontal

	//check if it fits in grid
	if (s->x + (not(s->type) * s->sizes[k]-1) > grid_size - 1) { return true; }
	if (s->y + (s->type * s->sizes[k]-1) > grid_size - 1) { return true; }
	
	//check if cells arent already taken by other ship
	for (int i = s->x; i <= s->x + (not(s->type) * (s->sizes[k]-1)); i++) {

		for (int j = s->y; j <= s->y + (s->type * (s->sizes[k]-1)); j++) {

			if (grid[i][j]!=0) {
				return true;
			}

		}

	}
	return false;
	

}

void Player::GridAdd(Ship* s, int k) {

		for (int i = s->x; i <= s->x + (not(s->type) * (s->sizes[k]-1)); i++) {

			for (int j = s->y; j <= s->y + (s->type * (s->sizes[k]-1)); j++) {

				switch (k) {
				case 0: grid[i][j] = 1;
					break;
				case 1: grid[i][j] = 2;
					break;
				case 2: grid[i][j] = 3;
					break;
				case 3: grid[i][j] = 3;
					break;
				case 4: grid[i][j] = 4;
					break;
				}
				

			}

		}


}

int Player::HowManyLeft() {
	int counter = 0;
	for (int i = 0; i < grid_size; i++) {

		for (int j = 0; j < grid_size; j++) {

			if (grid[i][j] != 0 && grid[i][j] != -1) counter++;

		}
	}
	return counter;
}