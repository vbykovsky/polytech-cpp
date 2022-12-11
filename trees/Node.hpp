#pragma once

#include <iostream>

struct Node {
  int key = -1;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;

  int height = 1;

  Node() : key(-1) {}
  Node(int key): key(key) {}

  void print(const char[]);

  bool isNotDefined();
};

int getNodeHeight(Node*);

int getNodeBalanceFactor(Node*);

int restoreNodeHeight(Node*);