#pragma once

#include <iostream>

struct Node {
  int key = -1;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;

  Node(int key): key(key) {}

  void print(const char[]);
};