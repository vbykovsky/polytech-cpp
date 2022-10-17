#pragma once

#include "Weapon.hpp"

// #7
class MagicWeapon : public Weapon {
private:
  // #8
  float magicDamage;

public:
  // #9
  MagicWeapon();
  MagicWeapon(string, float, float, float, WeaponType);

public:
  ~MagicWeapon();

public:
  // #10
  float getMagicDamage();

public:
  friend ostream& operator<<(ostream&, MagicWeapon&);
};