#include <string>
#include <iostream>

using namespace std;

int main() {
  string str;

  // #1
  cout << "Enter a string: ";
  cin >> str;

  // #2
  cout << "Substring from 2 to 4: " << str.substr(1, 3) << endl;

  // #3
  int firstAIndex = str.find('a');

  if (firstAIndex >= 0) {
    cout << "First include of 'a' symbol on position: " << firstAIndex + 1 << endl;
  }
  else {
    cout << "'a' symbol wasn't found in string" << endl;
  }

  return 0;
}