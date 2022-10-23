#include <iostream>

#include "Player.hpp"
#include "Weapon.hpp"
#include "MagicWeapon.hpp"
#include "OneOffWeapon.hpp"
#include "WearableWeapon.hpp"

using namespace std;

int main() {
  // #4
  MagicWeapon LaserAk47("Laser AK-47", 30, 10, 3.2, WeaponType::TWOHANDED);
  cout << LaserAk47 << endl;
  LaserAk47.attack();

  // #8
  OneOffWeapon ZeusX27("ZeusX27", 90, 1, WeaponType::TWOHANDED);
  cout << ZeusX27 << endl;
  ZeusX27.attack();
  ZeusX27.attack();

  // #11
  WearableWeapon<MagicWeapon> wearableMagicWeapon(LaserAk47);
  WearableWeapon<OneOffWeapon> wearableOneOffWeapon(ZeusX27);
  
  cout << endl;

  return 0;
}