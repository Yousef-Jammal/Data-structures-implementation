#include <iostream>
using namespace std;


int main() {
  int x = 500;
  int *y ;

  y = &x; 
  cout << x << endl;
  cout << y << endl;

  return 0;
}