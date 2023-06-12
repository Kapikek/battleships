#include "Ship.h"


Ship::Ship(int i) {

	cout << "Ships length: " << sizes[i] << endl;
	int ans = 3;

	while (ans != 0 and ans != 1) {
		cout << "(0) Place it vertically" << endl;
		cout << "(1) Place it horizontally" << endl;
		cin >> ans;
	}

	type = ans;

	string coords = GetCoords();
	int coordsint = stoi(coords);
	y = coordsint / 10;
	x = coordsint % 10;

	
}

Ship::Ship(int xx, int yy, bool typee) {

	x = xx;
	y = yy;
	type = typee;

}

string Ship::GetCoords() {

	string alf = "ABCDEFGHIJ";

	char let;

	int ans1=0, ans2=0;
	bool flag = 0;
	while (flag == 0) {
		cout << "Which column? (A - J)" << endl;
		cin >> let;
		let = toupper(let);
		for (auto i : alf) {
			if (let == i) {
				ans1 = i;
				flag = 1;
			}
		}
	}
	flag = 0;
	while (flag == 0) {
		cout << "Which row? (1 - 10)" << endl;
		cin >> ans2;

		for (int i = 1; i <= 10; i++) {
			if (ans2 == i) {
				ans2 = i - 1;
				flag = 1;
			}
		}
	}

	return to_string(10 * ans1 + ans2-650); //no idea why there is -650, but it works
	//returns 2 (or 1 if ans1 = 0) digit string indicating our coordinates
}

