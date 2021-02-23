#include "std_lib_facilities.h"

int main () {
	vector <int> vals;
	vector <int> guesses;
	int randNum, bulls, cows = 0;
	
	srand((unsigned) time(0));

	while (vals.size() < 4) {
		randNum = (rand() % 10); 
		bool valid = true;

		for (int n : vals) {
			if (n == randNum) valid = false;
		}

		if (valid == true) vals.push_back(randNum);
	}

	for (int v : vals) cout << v;

	bool is_correct = false;

	while (!is_correct) {
		int g;
		bulls = 0;
		cows = 0;

		cout << "\nGuess the value: ";
		cin >> g; 
		int a = g % 10;
		int b = (g % 100 - a) / 10; 
		int c = (g % 1000 - (10*b + a)) / 100; 
		int d = (g - (100*c + 10*b + a)) / 1000;

		guesses = {d, c, b, a};

		for (int i = 0; i < 4; ++i) {
			bool is_cow = false;
			for (int n : vals) {
				if (guesses[i] == n && guesses[i] != vals[i]) is_cow = true;
			}

			if (guesses[i] == vals[i]) ++bulls;
			else if (is_cow == true) ++cows;
		}
		
		cout << "cows: " << cows << endl;
		cout << "bulls: " << bulls << endl;

		if (bulls == 4) is_correct = true;
	}

	cout << "Correct!" << endl;

	return 0;
}
