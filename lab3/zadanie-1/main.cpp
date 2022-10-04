#include <iostream>

using namespace std;

int main() {
  // #1
  int a = 12345;
  // #2
  int* a_ptr = &a;

  // #3
  cout << "pointer value: " << a_ptr << ", variable value: " << *a_ptr << endl;

  // #4
  *a_ptr = 6789;

  // #5
  cout << "variable value: " << a  << endl;

  // #6
  int array[] = { 1, 2, 3, 4, 5 };

  // #7
  cout << *array << " " << *(array + 1) << " " << *(array + 2) << " " << *(array + 3) << " " << *(array + 4) << endl;

  // #8
  int c = 5;

  // #9
  int* const c_ptr = &c;

  // #10
  
  // E0137: expression must be a modifiable value
  //c_ptr = &a;

  *c_ptr = 10;
  cout << "now c value is " << c << endl;

  return 0;
}