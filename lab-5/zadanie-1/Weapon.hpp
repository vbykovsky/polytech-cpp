#pragma once

#include <string>
#include <iostream>

using namespace std;

// #1
enum class WeaponType : int {
  ONEHANDED,
  TWOHANDED,
  BOW,
  CROSSBOW,
};

class Weapon {
private:
  float damage;
  float weight;
  string title;
  // #2
  WeaponType type;

public:
  Weapon();
  // #2
  Weapon(string, float, float, WeaponType);

public:
  ~Weapon();

public:
  string getTitle();

  float getWeight();

  float getDamage();

  // #2
  WeaponType getType();

public:
  void setDamage(float);

public:
  friend ostream& operator<<(ostream&, Weapon&);

public:
  bool canTake(float);

  float getSumWeightWith(float);

  float getSumWeightWith(Weapon&);

  string getTypeTitle();
};