#include <iostream>

#include "Tree.hpp"

using namespace std;


int main() {
  #pragma region init tree
  Node rootNode(10);
  Node node1(5);
  Node node2(15);

  rootNode.left = &node1;
  rootNode.right = &node2;

  node1.parent = &rootNode;
  node2.parent = &rootNode;

  Node node3(2);
  Node node4(8);

  node1.left = &node3;
  node1.right = &node4;

  node3.parent = &node1;
  node4.parent = &node1;

  Node node5(12);
  Node node6(18);

  node2.left = &node5;
  node2.right = &node6;

  node5.parent = &node2;
  node6.parent = &node2;

  Tree tree(&rootNode);

  tree.pushNode(&node1);
  tree.pushNode(&node2);
  tree.pushNode(&node3);
  tree.pushNode(&node4);
  tree.pushNode(&node5);
  tree.pushNode(&node6);
  #pragma endregion

  return 0;
}