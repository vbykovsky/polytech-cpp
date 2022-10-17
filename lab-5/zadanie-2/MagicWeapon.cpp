#include "MagicWeapon.hpp"

MagicWeapon::MagicWeapon(): Weapon(), magicDamage(0) {}

MagicWeapon::MagicWeapon(string title, float damage, float magicDamage, float weight, WeaponType type): Weapon(title, damage, weight, type), magicDamage(magicDamage) {}

MagicWeapon::~MagicWeapon() {
  cout << *this << " | Was deleted" << endl;
}

float MagicWeapon::getMagicDamage() {
  return this->magicDamage;
}

// #2
float MagicWeapon::getFullDamage() {
  return this->getDamage() + this->getMagicDamage();
}

ostream& operator<<(ostream& out, MagicWeapon& weapon) {
  out << weapon.getTypeTitle() << "(Magic) \"" << weapon.getTitle() << "\": damage=" << weapon.getFullDamage() << "(" << weapon.getMagicDamage() << " magic), weight=" << weapon.getWeight() << "kg";

  return out;
}