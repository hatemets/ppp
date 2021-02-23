#include "std_lib_facilities.h"

int main () {
	vector <int> fib;
	int n, val = 0;
	cout << "How many values to show? ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		if (i < 2) val = 1;
		else val = fib[i - 2] + fib[i - 1];

		fib.push_back(val);
	}

	for (int n : fib) cout << n << endl;

	return 0;
}
