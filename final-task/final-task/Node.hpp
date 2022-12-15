#pragma once

class Node abstract {
public:
  const int value = -1;
  
public:
  Node* left = nullptr;
  Node* right = nullptr;

public:
  Node(int value);

public:
  virtual void display() = 0;
};