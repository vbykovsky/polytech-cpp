#include "Weapon.hpp"


Weapon::Weapon() : Weapon("Untitled", 0, 0) {}
Weapon::Weapon(string title, float damage, float weight) : title(title), damage(damage), weight(weight) {}

Weapon::~Weapon() {
  cout << *this << " | Was deleted" << endl;
}

ostream& operator<<(ostream& out, Weapon& weapon) {
  out << "Weapon \"" << weapon.title << "\": damage=" << weapon.damage << ", weight=" << weapon.weight << "kg";

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