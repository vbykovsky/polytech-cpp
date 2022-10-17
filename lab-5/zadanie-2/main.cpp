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

  cout << Glock18 << endl;
  cout << Ak47 << endl;
  cout << Bow << endl;
  cout << Crossbow << endl;

  MagicWeapon LaserAk47("Laser AK-47", 30, 10, 3.2, WeaponType::TWOHANDED);

  // #3
  cout << LaserAk47 << endl;

  // #5
  cout << "Is AK-47 > Laser AK-47: " << (Ak47 > LaserAk47 ? "Yes" : "No") << endl;
  cout << "Is Laser AK-47 > AK-47: " << (LaserAk47 > Ak47 ? "Yes" : "No") << endl;

  cout << endl;

  return 0;
}