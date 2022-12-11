#pragma once

#include "Tree.hpp"
#include "AVLNode.hpp"

class AVLTree : public Tree<AVLNode> {
public:
  AVLTree();
  ~AVLTree();

public:
  int find(int value) const;
  void insert(int value);
  void erase(int value);
  void clear();

public:
  int getSize() const;
  bool isEmpty() const;

public:
  void balance(std::vector<AVLNode**> path);

public:
  void display();
  void display(AVLNode* cur, int depth = 0, int state = 0);

public:
  void printBalancedOrder();
};