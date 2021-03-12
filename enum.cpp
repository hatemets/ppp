#include "std_lib_facilities.h"

enum Day {
    mon, tue, wed, thu, fri, sat, sun // mon=0
};

enum class Month {
    // enum class means that the items are in this scope only
    jan=1, feb, mar // feb=2, mar=3
};

int main () {
    cout << int(Month::mar) << endl;
    cout << int(Day::mon) << endl;
    return 0;
}

