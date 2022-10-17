#include "Weapon.hpp"


Weapon::Weapon() : Weapon("Untitled", 0, 0, WeaponType::TWOHANDED) {}
Weapon::Weapon(string title, float damage, float weight, WeaponType type) : title(title), damage(damage), weight(weight), type(type) {}

Weapon::~Weapon() {
  cout << *this << " | Was deleted" << endl;
}

string Weapon::getTitle() {
  return this->title;
}

float Weapon::getWeight() {
  return this->weight;
}

float Weapon::getDamage() {
  return this->damage;
}

void Weapon::setDamage(float damage) {
  this->damage = damage;;
}

ostream& operator<<(ostream& out, Weapon& weapon) {
  out << weapon.getTypeTitle() << " \"" << weapon.getTitle() << "\": damage=" << weapon.getDamage() << ", weight=" << weapon.getWeight() << "kg";

  return out;
}

bool Weapon::canTake(float maxWeight) {
  return maxWeight >= this->weight;
}

float Weapon::getSumWeightWith(float loadWeight) {
  return this->weight + loadWeight;
}

float Weapon::getSumWeightWith(Weapon& weapon) {
  return getSumWeightWith(weapon.weight);
}

string Weapon::getTypeTitle() {
  switch (this->type) {
  case WeaponType::ONEHANDED:
    return "Onehanded Weapon";
  case WeaponType::TWOHANDED:
    return "Twohanded Weapon";
  case WeaponType::BOW:
    return "Bow Weapon";
  case WeaponType::CROSSBOW:
    return "Crossbow Weapon";

  default:
    return "Unknown Weapon";
  }
}
