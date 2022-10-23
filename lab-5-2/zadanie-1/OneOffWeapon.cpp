#include "OneOffWeapon.hpp"

OneOffWeapon::OneOffWeapon() : Weapon(), isUsed(false) {}

OneOffWeapon::OneOffWeapon(string title, float damage, float weight, WeaponType type) : Weapon(title, damage, weight, type), isUsed(false) {}

// #7
void OneOffWeapon::attack(){
  if (this->isUsed) {
    cout << "Weapon has already been used" << endl;
  }
  else {
    this->isUsed = true;

    cout << "Attacking with One-off Weapon" << endl;
  }
}
