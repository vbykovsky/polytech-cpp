#include <iostream>

using namespace std;

// #1
int arraySum(int* begin, int* end) {
  int sum = 0;

  int* pointer = begin;

  for (int* pointer = begin; pointer != end; pointer++) {
    sum += *pointer;
  }

  return sum;
}

// #3
int sum(int a, int b) {
  return a + b;
}

int diff(int a, int b) {
  return a - b;
}

// #4,5
int(*getOperand(char operandSymbol))(int, int) {
  if (operandSymbol == '+') {
    return sum;
  }

  return diff;
}

int main() {
  // #2
  int array[] = { 1, 2, 3, 4, 5 };

  cout << "sum of array is " << arraySum(array, (array + 4)) << endl;

  // #6
  auto sumOperand = getOperand('+');
  cout << "sumOperand of 1 and 2 returns " << sumOperand(1, 2) << endl;

  auto diffOperand = getOperand('-');
  cout << "diffOperand of 1 and 2 returns " << diffOperand(1, 2) << endl;

  // #7
  float* a = new float(1.1);

  // #8
  cout << *a << endl;
  delete a;

  return 0;
}