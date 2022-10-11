#pragma once

class Weapon;

// #5
class Characteristic {
private:
  float strength;

public:
  Characteristic(float);

public:
  // #7
  float getDamage(Weapon&);
};