#pragma once

#include "Weapon.hpp"

// #5
class OneOffWeapon : public Weapon {
private:
  // #6
  bool isUsed;

public:
  OneOffWeapon();
  OneOffWeapon(string, float, float, WeaponType);

public:
  // #7
  void attack();
};