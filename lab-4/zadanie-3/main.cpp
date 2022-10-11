#include <iostream>

#include "Weapon.hpp"

using namespace std;

int main() {
  Weapon ak47("AK-47", 30, 4.3);
  cout << ak47 << endl;

  Weapon* m4a1 = new Weapon("M4A1", 27, 4);
  cout << *m4a1 << endl;

  cout << "Can I take AK-47 if I can only take 4kg: " << (ak47.canTake(4) ? "Yes" : "No") << endl;
  cout << "Weight of AK-47 with 10kg load is " << ak47.getSumWeightWith(10) << endl;
  cout << "Weight of AK-47 and M4A1 is " << ak47.getSumWeightWith(*m4a1) << endl;

  delete m4a1;

  return 0;
}