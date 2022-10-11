#include <string>
#include <iostream>

using namespace std;

class Weapon {
private:
  float damage;
  float weight;
  string title;

public:
  Weapon(): Weapon("Untitled", 0, 0) {}
  Weapon(string title, float damage, float weight): title(title), damage(damage), weight(weight) {}

  // #1
  ~Weapon() {
    cout << *this << " | Was deleted" << endl;
  }

  friend ostream& operator<<(ostream& out, Weapon& weapon) {
    out << "Weapon \"" << weapon.title << "\": damage=" << weapon.damage << ", weight=" << weapon.weight << "kg";

    return out;
  }

  // #5
  bool canTake(float maxWeight) {
    return maxWeight >= this->weight;
  }

  // #7
  float getSumWeightWith(float loadWeight) {
    return this->weight + loadWeight;
  }

  // #6
  float getSumWeightWith(Weapon& weapon) {
    // #8
    return getSumWeightWith(weapon.weight);
  }
};

int main() {
  // #2
  Weapon ak47("AK-47", 30, 4.3);
  cout << ak47 << endl;

  // #3
  Weapon* m4a1 = new Weapon("M4A1", 27, 4);
  cout << *m4a1 << endl;

  // #9
  cout << "Can I take AK-47 if I can only take 4kg: " << (ak47.canTake(4) ? "Yes" : "No") << endl;
  cout << "Weight of AK-47 with 10kg load is " << ak47.getSumWeightWith(10) << endl;
  cout << "Weight of AK-47 and M4A1 is " << ak47.getSumWeightWith(*m4a1) << endl;

  // #4
  delete m4a1;

  return 0;
}