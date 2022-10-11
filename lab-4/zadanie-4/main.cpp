#include <iostream>

#include "MyMath.hpp"
#include "Weapon.hpp"
#include "Characteristic.hpp"

using namespace std;

int main() {
  Weapon ak47("AK-47", 30, 4.3);
  cout << ak47 << endl;

  Weapon* m4a1 = new Weapon("M4A1", 27, 4);
  cout << *m4a1 << endl;

  cout << "Can I take AK-47 if I can only take 4kg: " << (ak47.canTake(4) ? "Yes" : "No") << endl;
  cout << "Weight of AK-47 with 10kg load is " << ak47.getSumWeightWith(10) << endl;
  cout << "Weight of AK-47 and M4A1 is " << ak47.getSumWeightWith(*m4a1) << endl;

  // #4
  cout << "AK-47 title: " << ak47.getTitle() << endl;
  cout << "AK-47 weight: " << ak47.getWeight() << endl;
  cout << "AK-47 damage: " << ak47.getDamage() << endl;

  ak47.setDamage(31);
  cout << "AK-47 new damage: " << ak47.getDamage() << endl;

  // #8
  Characteristic ak47Characteristic(10);
  cout << "AK-47 characteristic is " << ak47Characteristic.getDamage(ak47) << endl;

  // #12
  cout << "MyMath: 1 + 2 = " << MyMath::add(1, 2) << endl;
  cout << "MyMath: 1 - 2 = " << MyMath::sub(1, 2) << endl;
  cout << "MyMath: 1 * 2 = " << MyMath::mult(1, 2) << endl;
  cout << "MyMath: 1 / 2 = " << MyMath::div(1, 2) << endl;

  // #13
  cout << MyMath::callsCount << " calls were done of static methods in MyMath" << endl;

  delete m4a1;

  return 0;
}