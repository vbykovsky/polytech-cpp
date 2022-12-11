#pragma once

#include <iostream>

#include "Node.hpp"

class AVLNode: public Node {
public:
  int height = 0;

public:
  AVLNode* left = nullptr;
  AVLNode* right = nullptr;

public:
  AVLNode(int value);

public:
  void updateValues();
  int balanceFactor();

  AVLNode* leftRotate();
  AVLNode* rightRotate();
};