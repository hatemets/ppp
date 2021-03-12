#include "std_lib_facilities.h"

struct Box {
    Box (int n) : y{n} { }
    int y = 0;
};

Box operator++ (Box& b) {
    return b.y++;
}

int main () {
    Box b1{2};
    cout << b1.y << endl;
    ++b1;
    cout << b1.y << endl;
    return 0;
}

