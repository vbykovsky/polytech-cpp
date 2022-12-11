#pragma once

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

template<class Node>
class Tree abstract {
protected:
  int size = 0;
  Node* root = nullptr;

public:
  virtual int find(int value) const = 0;
  virtual void insert(int value) = 0;
  virtual void erase(int value) = 0;
  virtual void clear() = 0;

public:
  virtual void balance(std::vector<Node**> path) = 0;

public:
  virtual void display() = 0;
};