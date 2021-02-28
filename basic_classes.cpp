#include "std_lib_facilities.h"

class House {
    int width, height;
  public:
    House ();
    House (int, int);
    int area () {
      return width * height;
    }
};

House::House () {
  width = 5;
  height = 5;
}

House::House (int w, int h) {
  width = w;
  height = h;
}

int main () {
  House h1;
  House h2 {}; // the optimal method: shows that this is calling class
  House h3 {1, 3};
  House h4 (9, 2);
  cout << h1.area() << endl;
  cout << h2.area() << endl;
  cout << h3.area() << endl;
  cout << h4.area() << endl;
  return 0;
}
