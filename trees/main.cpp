#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Node.hpp"
#include "Tree.hpp"
#include "AVLTree.hpp"

using namespace std;

size_t split(const string& txt, vector<string>& strs, char ch){
  size_t pos = txt.find(ch);
  size_t initialPos = 0;
  strs.clear();

  while (pos != string::npos) {
    strs.push_back(txt.substr(initialPos, pos - initialPos));
    initialPos = pos + 1;

    pos = txt.find(ch, initialPos);
  }

  strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));

  return strs.size();
}


int main() {
  string inputStr = "";
  getline(cin, inputStr);

  vector<string> keysStrs;
  auto keysCount = split(inputStr, keysStrs, ' ');

  vector<int> keys;
  for (auto keyStr: keysStrs) {
    keys.push_back(stoi(keyStr));
  }

  sort(keys.begin(), keys.end());

  Node AVLRootNode(keys[keysCount / 2]);
  AVLTree AVLTree(&AVLRootNode);

  Node AVLNodes[100] = {};

  for (int i = 0; i < keysCount; i++) {
    int key = keys[i];

    AVLNodes[i] = *(AVLTree.insert(&AVLRootNode, key));
    if (AVLNodes[i].isNotDefined()) {
      cout << "Failed to insert ";
      AVLNodes[i].print("AVLNodes[i]");
    }
  }

  cout << endl;


  return 0;
}