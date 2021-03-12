#include "std_lib_facilities.h" 
void swap (int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main () {
  int x = 2;
  int y = 3;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;

  swap (x, y);
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  return 0;
}
