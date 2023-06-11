#include "GameFlow.h"

GameFlow::GameFlow() {

	Intro();

	cout << "Choose your gamemode" << endl;
	cout << "(1)Player vs Player" << endl;
	cout << "(2)Player vs AIris the Dumb" << endl;
	string kp = "3";
	while (kp != "1" && kp != "2") {
		cin >> kp;
	}

	if (kp == "1") {  //(1)Player vs Player

		string P1name, P2name;
		cout << "(P1) Please enter your name:" << endl;
		cin >> P1name;
		cout << "(P2) Please enter your name:" << endl;
		cin >> P2name;
		Player* P1 = new Player(P1name);
		Player* P2 = new Player(P2name);	

		cout << P1->name << ", its your turn to place ships, cover the screen from your opponent!" << endl;
		P1->AddShips();
		Sleep(5000);
		system("cls");
		cout << P2->name << ", its your turn to place ships, cover the screen from your opponent!" << endl;
		P2->AddShips();
		Sleep(5000);
		system("cls");

		players.push_back(P1);
		players.push_back(P2);

		while (P1->HowManyLeft() != 0 && P2->HowManyLeft() != 0) {
			for (int i = 0; i < 2; i++) {

				cout << "Turn of: " << "\033[1;45m" << players[i]->name << "\033[0m" << endl;

				Shoot(players[i], players[(i + 1) % 2]);

				if (players[(i + 1) % 2]->HowManyLeft() == 0) break;
				Sleep(2000);
				system("cls");

			}
		}

		if (P1->HowManyLeft() == 0) cout << P2->name << " won!";
		else cout << P1->name << " won!";



	}
	else {           //(2)Player vs AIris the Dumb

		string P1name;
		cout << "Please enter your name:" << endl;
		cin >> P1name;

		Player* P1 = new Player(P1name);
		Computer* P2 = new Computer("AIris the Dumb");

		
	}



}


void GameFlow::Shoot(Player* shooter, Player* victim) {
	int x, y;
	do {

		cout << "Take your shot!" << endl;
		victim->PrintGrid(1);
		string coords = shooter->ships[0]->GetCoords();
		int coordsint = stoi(coords);
		y = coordsint / 10;
		x = coordsint % 10;
		if (victim->grid[x][y] != 0 && victim->grid[x][y] != -1) {
			victim->grid[x][y] = -1; //mark as shot down
			cout << "Good shot!" << endl;
		}


	} while (victim->grid[x][y] != 0 && victim->HowManyLeft() !=0);
	


}

void GameFlow::Intro() {
	cout << "\033[1;32m";
	cout << "-------------------------------" << endl;
	cout << "Welcome to my Battleships game!" << endl;
	cout << "-------------------------------" << endl << endl;
	cout << "Both you and your opponent have 5 ships:" << endl;
	cout << "5x1, 4x1, 3x1, 3x1 and 2x1" << endl;
	cout << "The goal is to hide your ships well and " << endl;
	cout << "shoot all of the ships of your opponent" << endl << endl;
	cout << "Have fun!" << endl <<endl;
	cout << "\033[0m";
}

