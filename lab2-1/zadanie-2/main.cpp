#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  cout << "Avg: " << float(a + b) / 2 << endl;

  char numbersOperator = '\0';
  cout << "Enter te operator: ";
  cin >> numbersOperator;

  /*
  if (numbersOperator == '+') {
    cout << a << " " << numbersOperator << " " << b << " = " << a + b << endl;
  }
  else if (numbersOperator == '-') {
    cout << a << " " << numbersOperator << " " << b << " = " << a - b << endl;
  }
  else if (numbersOperator == '*') {
    cout << a << " " << numbersOperator << " " << b << " = " << a * b << endl;
  }
  else if (numbersOperator == '/') {
    cout << a << " " << numbersOperator << " " << b << " = " << a / b << endl;
  }
  else {
    cout << "Incorrect operator" << endl;
  }
  */

  switch (numbersOperator) {
    case '+':
      cout << a << " " << numbersOperator << " " << b << " = " << a + b << endl;
      break;
    case '-':
      cout << a << " " << numbersOperator << " " << b << " = " << a - b << endl;
      break;
    case '*':
      cout << a << " " << numbersOperator << " " << b << " = " << a * b << endl;
      break;
    case '/':
      cout << a << " " << numbersOperator << " " << b << " = " << a / b << endl;
      break;
    default:
      cout << "Incorrect operator" << endl;
  }

  return 0;
}