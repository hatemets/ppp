#include "../std_lib_facilities.h"

int main () {
	cout << "enter the value of a, b and c for ax2 + bx + c: ";
	double a, b, c;
	cin >> a >> b >> c;

	double disc = b * b - 4 * a * c;
	if (disc < 0)
		cout << "discrimant is negative, no real roots" << endl;
	else if (disc >= 0) {
		double x1 = (-1 * b + disc) / (2 * a);
		double x2 = (-1 * b - disc) / (2 * a);
		if (x1 == x2)
			cout << "There is one solution: " << x1 << endl;
		else
			cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
	}

	return 0;
}
