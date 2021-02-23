#include "std_lib_facilities.h"

double converter (double t, char type) {
	double ans = 0;
	if (type == 'f')
		ans = (t * 9 / 5) + 32;
	else if (type == 'c')
		ans = (t - 32) * 5 / 9;
	return ans;
}

int main () {
	double temp = 0;
	char symbol;
	cout << "enter temperature and to which type u wish to convert: ";
	cin >> temp >> symbol;

	double val = converter(temp, symbol);
	cout << val << endl;
	return 0;
}
