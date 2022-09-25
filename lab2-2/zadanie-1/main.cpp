#include <iostream>

using namespace std;

// #10
unsigned int sumToNumber(int number = 1) {//# 11
  if (number <= 0) {
    return 0;
  }

  return float(1 + number) / 2 * number;
}

// #12
void calculate(int a, int b, int& c, int& d) {
  // #12
  c = a + b;
  d = a * b;
}

int main() {
  // #1
  int array[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

  // #2
  int sum = 0;

  for (auto& a: array) {
    for (auto& aa : a) {
      sum += aa;
    }
  }

  cout << "Sum of created array: " << sum << endl;

  // #3
  int array2[3] = { 0, 0, 0 };

  // #4
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      array2[j] += array[i][j];
    }
  }

  // #5
  cout << "array2: ";
  for (int i = 0; i < 3; i++) {
    cout << array2[i] << ", ";
  }
  cout << endl;

  // #6
  float a = 20.84;

  // #7
  float& aa = a;
  float& ba = a;

  // #8
  ba = 57.11;

  // #9
  cout << "a = " << a << ", aa = " << aa << ", ba = " << ba << endl;

  // #11
  cout << sumToNumber() << endl;

  // #14
  int b = 1, c = 2, d = 0, e = 0;

  calculate(b, c, d, e);

  cout << b << " + " << c << " = " << d << endl;
  cout << b << " * " << c << " = " << e << endl;

  // #15
  int f = 101;

  // #16
  for (int i = 0; i < 3; i++) {
    cout << f;

    // #17
    int g = 202;

    // #18
    for (int j = 0; j < 3; j++) {
      cout << g;
    }
  }
  cout << endl;

  // #19
  // Error C2065: 'g': undeclared identifier
  // cout << g << endl;

  return 0;
}