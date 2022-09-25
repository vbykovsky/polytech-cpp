//#6
#include <iostream>

#include "test.hpp"

//#7
void test::test(int a) {
  using namespace std;

  static int b = 0;

  cout << "(test): sum of a and b is " << a + b << endl;

  b = a;
}