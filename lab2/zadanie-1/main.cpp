#include <iostream>

using namespace std;

int main() {
  int a = 1, b = 2, c = 3;

  cout << "Sum a+b = " << a + b << endl;
  cout << "Diff b-c = " << b - c << endl;
  cout << "Mult c*a = " << c * a << endl;
  cout << "Quot c/b = " << c/b << endl;

  cout << "Rem a%b = " << a % b << endl;

  cout << "(((145 - 100 / 20) / 20) * 50) + 45 = " << (((145 - 100 / 20) / 20) * 50) + 45 << endl;

  int d = 3, e = 7;

  int f = d & e;
  int g = d | e;
  int h = d ^ e;

  int i = ~f;
  int j = f >> 1;
  int k = f << 1;

  cout << "d = " << d << endl;
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;
  cout << "g = " << g << endl;
  cout << "h = " << h << endl;
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  cout << "k = " << k << endl;

  bool trufy = true, falsy = false;
  bool res = trufy && (trufy && (trufy && trufy || falsy) && (falsy || trufy != falsy));

  cout << "res = " << res << endl;

  cout << "25 < 48 && (23 > (3 + 15) || (2 < 8 && (5 >= 2 && 15 < 15))) = " << (25 < 48 && (23 > (3 + 15) || (2 < 8 && (5 >= 2 && 15 < 15)))) << endl;

  return 0;
}