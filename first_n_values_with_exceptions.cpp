#include "std_lib_facilities.h"

int main () {
	try {
		vector <double> vals;
		vector <double> diffs;
		double val, total = 0;
		int n = 0;

		cout << "enter the number of values: ";
		cin >> n;

		cout << "enter some values for the list: ";
		while (cin >> val) vals.push_back(val);
	
		if (n > vals.size()) 
			error("there are not that many values in the vector");

		cout << "The sum of the first " << n << " values (";

		for (int i = 0; i < n; ++i) {
			total += vals[i];

			if ((i + 1) < vals.size())
				diffs.push_back(abs(vals[i] - vals[i + 1]));

			if (i < (n-1)) cout << vals[i] << " ";
			else cout << vals[i];
		}

		cout << ") is " << total << endl;

		cout << "differences: " << endl;
		for (double d : diffs) cout << d << endl;

		return 0;	
	} catch (exception& e) {
		cerr << "error: " << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "unknown error" << endl;;
		return 2;
	}
}
