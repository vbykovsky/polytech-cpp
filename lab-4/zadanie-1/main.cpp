#include <string>
#include <iostream>

using namespace std;

// #1
class Weapon {
private:
  float damage;
  float weight;
  string title;

public:
  // #3
  Weapon(): Weapon("Untitled", 0, 0) {}
  // #2
  Weapon(string title, float damage, float weight): title(title), damage(damage), weight(weight) {}

  friend ostream& operator<<(ostream& out,Weapon& weapon) {
    out << "Weapon \"" << weapon.title << "\": damage=" << weapon.damage << ", weight=" << weapon.weight << "kg";

    return out;
  }
};

int main() {
  // #4
  Weapon ak47("AK-47", 30, 4.3);
  Weapon untitledWeapon;

  // #5
  cout << ak47 << endl << untitledWeapon << endl;

  return 0;
}