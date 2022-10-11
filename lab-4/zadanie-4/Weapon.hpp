#pragma once

#include <string>
#include <iostream>

#include "Characteristic.hpp"

using namespace std;

class Weapon {
  // #6
  friend class Characteristic;
private:
  // #1
  float damage;
  float weight;
  string title;

public:
  Weapon();
  Weapon(string, float, float);

public:
  ~Weapon();

public:
  // #2
  string getTitle();

  float getWeight();

  float getDamage();

public:
  // #3
  void setDamage(float);

public:
  friend ostream& operator<<(ostream&, Weapon&);

public:
  bool canTake(float);

  float getSumWeightWith(float);

  float getSumWeightWith(Weapon&);
};