#pragma once

#include "Weapon.hpp"

class MagicWeapon : public Weapon {
private:
  float magicDamage;

public:
  MagicWeapon();
  MagicWeapon(string, float, float, float, WeaponType);

public:
  ~MagicWeapon();

public:
  float getMagicDamage();

  virtual float getFullDamage();

public:
  friend ostream& operator<<(ostream&, MagicWeapon&);

public:
  void attack();
};