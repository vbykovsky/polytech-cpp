#include <iostream>

using namespace std;

int main() {
  int a;

  do {
    cout << "Enter positive number: ";
    cin >> a;
  } while (a <= 0);

  cout << "Sum all numbers to " << a << " equals: " << (float(1 + a) / 2) * a << endl;

  int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      cout << array[i] << " ";
    }
  }
  cout << endl;

  int sum = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2) {
      sum += array[i];
    }
  }
  cout << "Sum: " << sum << endl;

  return 0;
}