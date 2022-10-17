#include <iostream>

#include "Player.hpp"
#include "Weapon.hpp"
#include "MagicWeapon.hpp"

using namespace std;

int main() {
  Weapon Glock18("Glock-18", 20, 2, WeaponType::ONEHANDED);
  Weapon Ak47("AK-47", 30, 3, WeaponType::TWOHANDED);
  Weapon Bow("Bow", 10, 0.5, WeaponType::BOW);
  Weapon Crossbow("Crossbow", 12, 0.8, WeaponType::CROSSBOW);

  // #3: Not with ifs, I did in getTypeTitle function
  cout << Glock18 << endl;
  cout << Ak47 << endl;
  cout << Bow << endl;
  cout << Crossbow << endl;

  Player John("John", "MyStrongPassword");

  // #6
  cout << John << endl;

  // #11
  MagicWeapon LaserAk47("Laser AK-47", 30, 10, 3.2, WeaponType::TWOHANDED);

  cout << LaserAk47 << endl;
  cout << "Can I take Laser AK-47 if I can only take 2kg:" << (LaserAk47.canTake(4) ? "Yes" : "No") << endl;
  cout << "Weight of Laser AK-47 and Glock-18 is " << LaserAk47.getSumWeightWith(Glock18) << endl;

  cout << endl;

  return 0;
}