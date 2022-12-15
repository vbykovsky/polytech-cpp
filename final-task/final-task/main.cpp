#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

#include "AVLTree.hpp"

using namespace std;

int main() {
  cout << "Hello! This program will help you get the sequence to get a balanced AVL tree" << endl << endl;

  AVLTree tree;

  int size;
  cout << "Enter sequence size: ";
  cin >> size;

  cout << "Enter sequence: ";
  for (int i = 0; i < size; i++) {
    int x;
    cin >> x;

    if (tree.find(x) == nullptr) {
      tree.insert(x);
    }
    else {
      cout << endl << "Sorry, we cant insert repeating element(" << x << ")";
    }
  }

  cout << endl << endl << "Your balanced AVL tree:";

  tree.display();

  cout << endl << "Your  sequence to get a balanced AVL tree:" << endl;
  tree.displayBalancedOrder();

  cout << endl << endl;

  system("pause");

  return 0;
}