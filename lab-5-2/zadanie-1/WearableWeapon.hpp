#pragma once

#include <vector>

#include "Weapon.hpp"

// #9
template<class WeaponClass>
class WearableWeapon {
private:
  WeaponClass* leftHand;
  WeaponClass* rightHand;
  WeaponClass* back;

  vector<WeaponClass*> weapons;

public:
  // #10
  WearableWeapon() : leftHand(nullptr), rightHand(nullptr) {};
  WearableWeapon(WeaponClass& weapon) : WearableWeapon() {
    this->take(&weapon);
  }

public:
  // #10
  WeaponClass* drop() {
    if (weapons.size() > 0) {
      WeaponClass* lastWeapon = this->weapons[this->weapons.size() - 1];

      if (lastWeapon->getType() == WeaponType::ONEHANDED) {
        if (this->leftHand == lastWeapon) {
          this->leftHand = nullptr;
        }
        else {
          this->rightHand = nullptr;
        }
      }
      else if (lastWeapon->getType() == WeaponType::TWOHANDED) {
        this->leftHand = nullptr;
        this->rightHand = nullptr;
      }
      else if (lastWeapon->getType() == WeaponType::BOW) {
        this->leftHand = nullptr;
        this->rightHand = nullptr;
        this->back = nullptr;
      }
      else if (lastWeapon->getType() == WeaponType::CROSSBOW) {
        this->leftHand = nullptr;
        this->rightHand = nullptr;
        this->back = nullptr;
      }

      return lastWeapon;
    }

    return nullptr;
  };

  void take(WeaponClass* weapon) {
    this->weapons.push_back(weapon);

    if (weapon->getType() == WeaponType::ONEHANDED) {
      this->leftHand = weapon;
    }
    else if (weapon->getType() == WeaponType::TWOHANDED) {
      this->leftHand = weapon;
      this->rightHand = weapon;
    }
    else if (weapon->getType() == WeaponType::BOW) {
      this->leftHand = weapon;
      this->rightHand = weapon;
      this->back = weapon;
    }
    else if (weapon->getType() == WeaponType::CROSSBOW) {
      this->leftHand = weapon;
      this->rightHand = weapon;
      this->back = weapon;
    }
  }
};