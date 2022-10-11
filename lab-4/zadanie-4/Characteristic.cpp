#include "Characteristic.hpp"
#include "Weapon.hpp"

Characteristic::Characteristic(float strength): strength(strength) {}

// #7
float Characteristic::getDamage(Weapon& weapon) {
  return this->strength + weapon.damage;
}