#include <clocale>
#include <Windows.h>

#include <string>
#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");


  int a = 150;
  float b = 15.933;
  unsigned short c = 250;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  const int birthDay = 29;
  const string birthMonth = "January";
  const int birthYear = 2003;

  cout << "Мой birthday on the " << birthDay << " of " << birthMonth << ", " << birthYear << endl;

  const float d = 2.3;
  const string windows = "WINDOWS";

  cout << d << " " << windows << endl;

  return 0;
}