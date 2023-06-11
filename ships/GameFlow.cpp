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

		GameLoop(P1, P2);

	}
	else {           //(2)Player vs AIris the Dumb

		string P1name;
		cout << "Please enter your name:" << endl;
		cin >> P1name;

		Player* P1 = new Player(P1name);
		Computer* P2 = new Computer("AIris the Dumb");

		GameLoop(P1, P2);
	}

}

void GameFlow::GameLoop(Player* P1, Player* P2) {

	players.push_back(P1);
	players.push_back(P2);






}

void GameFlow::Intro() {
	cout << "-------------------------------" << endl;
	cout << "Welcome to my Battleships game!" << endl;
	cout << "-------------------------------" << endl << endl;
	cout << "Both you and your opponent have 5 ships:" << endl;
	cout << "5x1, 4x1, 3x1, 3x1 and 2x1" << endl;
	cout << "The goal is to hide your ships well and " << endl;
	cout << "shoot all of the ships of your opponent" << endl << endl;
	cout << "Have fun!" << endl <<endl;
}