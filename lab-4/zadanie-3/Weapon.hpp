#pragma once

#include <string>
#include <iostream>

using namespace std;

class Weapon {
private:
  float damage;
  float weight;
  string title;

public:
  Weapon();
  Weapon(string, float, float);

  // #1
  ~Weapon();

  friend ostream& operator<<(ostream&, Weapon&);

  // #5
  bool canTake(float);

  // #7
  float getSumWeightWith(float);

  // #6
  float getSumWeightWith(Weapon&);
};