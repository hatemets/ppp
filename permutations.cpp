#include "std_lib_facilities.h"

double factorial (int n) {
    if (n == 0) return 1;
    else if (n < 0) error("negative number for factorial");
    double total = 1;

    for (n; n > 1; --n)
        total *= n;

    return total;
}

int perm (int a, int b) {
    return factorial(a) / (factorial(a - b));
}

int comb (int a, int b) {
    return perm(a, b) / factorial(b);
}

int main () {
    try {
        int a, b = 0;
        char type;
        cout << "enter two integeres: ";
        cin >> a >> b;
        cout << "permutation (p) or combination (c)? ";
        cin >> type;

        if (type == 'p')
            cout << perm(a, b) << endl;
        else if (type == 'c')
            cout << comb(a, b) << endl;
        else
            error("unknown type");


        return 0;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
    } catch (...) {
        cerr << "unknown exception" << endl;
    }
}
