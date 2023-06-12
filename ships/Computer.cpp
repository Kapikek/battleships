#include "Computer.h"


void Computer::AddShips() {

	cout << "AIris is kinda dumb, give her a moment to find correct ship placements" << endl;

	for (int i = 0; i < num_of_ships; i++) {



		srand((unsigned)time(NULL));

		int random = rand()%100;
		int y = random / 10;
		int x = random % 10;
		bool type = random % 2;

		Ship* s1 = new Ship(x, y, type);

		bool conflict = CheckForConflicts(s1, i);
		if (conflict) {
			i--;
		}
		else {
			ships.push_back(s1);
			GridAdd(s1, i);
		}

	}




}