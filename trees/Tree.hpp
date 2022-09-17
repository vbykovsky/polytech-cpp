#pragma once

#include <iostream>

#include "Node.hpp"

struct Tree {
  Node* root = nullptr;
  Node* nodes[100] = {};
  int nodesCount = 0;

  Tree() {}

  Tree(Node* root) : root(root) {
    this->pushNode(root);
  }

  int pushNode(Node*);
  int popNode(Node*);

  Node* find(int);
  Node* findLastNode(int);

  Node* min();
  Node* minFrom(Node*);

  Node* max();
  Node* maxFrom(Node*);

  Node* findNext(int);
  Node* findNext(Node*);

  void insert(int, Node*);

  Node* remove(int);
  Node* remove(Node*);
};