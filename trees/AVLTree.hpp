#pragma once

#include "Tree.hpp"

struct AVLTree : public Tree {
  Node* rotateRight(Node*);
  Node* rotateLeft(Node*);

  Node* balance(Node*);

  Node* insert(Node*, int);
};