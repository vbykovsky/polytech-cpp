#include <iostream>

#include "test.hpp"

//#5
#define SUM(a,b) ((a) + (b))

// #4
using namespace std;

// #1
/*
void test(int a) {
  static int b = 0;

  // #2
  cout << "(test): sum of a and b is " << a + b << endl;

  b = a;
}
*/

int main() {
  // #3
  /*
  test(1); // (test): sum of a and b is 1
  test(2); // (test): sum of a and b is 3
  test(3); // (test): sum of a and b is 5
  */

  // #8
  test::test(1);
  test::test(2);
  test::test(3);

  // #9
  system("pause");

  return 0;
}