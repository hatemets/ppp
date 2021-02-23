#include "../std_lib_facilities.h"

int main() {
	vector <int> primes;
	int max;
	cout << "enter how many primes: ";
	cin >> max;

	int n = 1;
	int counter = 0;
		
	while (counter < max) {
		if (n > 1 && n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0 || n == 2 || n == 3 || n == 5 || n == 7) {
			bool is_prime = true;
			for (int prime : primes) {
				if (n % prime == 0)
					is_prime = false;
			}

			if (is_prime == true) {
				primes.push_back(n);
				++counter;
			}
		}
		++n;
	}


	for (int prime : primes)
		cout << prime << endl;
	return 0;
}
