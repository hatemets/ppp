#include "std_lib_facilities.h"

struct Point {
    public:
        constexpr Point (double a, double b) : x(a), y(b) { }
        double x;
        double y;
};

constexpr double xscale = 3;
constexpr double yscale = 2;

constexpr Point scale(Point p) {
    return Point(p.x * xscale, p.y * yscale);
}

int main () {
    Point p1 = Point(5, 5);
    cout << "x: " << p1.x << endl << "y: " << p1.y << endl;
    Point p2 = scale(p1);
    cout << "x: " << p2.x << endl << "y: " << p2.y << endl;
    return 0;
}
