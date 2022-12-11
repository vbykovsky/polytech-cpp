#pragma once

class Node {
public:
  const int value = -1;

public:
  int size = 0;
  
public:
  Node* left = nullptr;
  Node* right = nullptr;

public:
  Node(int value);
};