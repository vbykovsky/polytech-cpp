#include "AVLTree.hpp"

Node* AVLTree::rotateRight(Node* node) {
  Node* leftNode = node->left;
  Node* leftNodeRightChild = leftNode->right;

  node->parent = leftNode;
  leftNode->right = node;

  node->left = leftNodeRightChild;

  if (leftNodeRightChild != nullptr) {
    leftNodeRightChild->parent = node;
  }

  restoreNodeHeight(node);
  restoreNodeHeight(leftNode);

  return leftNode;
}

Node* AVLTree::rotateLeft(Node* node) {
  Node* rightNode = node->right;
  Node* rightNodeLeftChild = rightNode->left;

  node->parent = rightNode;
  rightNode->left = node;

  node->right = rightNodeLeftChild;
  rightNodeLeftChild->parent = node;

  restoreNodeHeight(node);
  restoreNodeHeight(rightNode);

  return rightNode;
}

Node* AVLTree::balance(Node* node) {
  restoreNodeHeight(node);

  int nodeBalanceFactor = getNodeBalanceFactor(node);

  if (nodeBalanceFactor == 2) {
    if (getNodeBalanceFactor(node->right) < 0) {
      node->right = this->rotateRight(node->right);
    }

    return this->rotateLeft(node);
  }
  else if (nodeBalanceFactor == -2) {
    if (getNodeBalanceFactor(node->left) > 0) {
      node->left = this->rotateLeft(node->left);
    }

    return this->rotateRight(node);
  }

  return node;
}

Node* AVLTree::insert(Node* insertedNode, int key) {
  if (insertedNode == nullptr) {
    Node* newNode = new Node(key);
    this->pushNode(newNode);

    return newNode;
  }

  if (key < insertedNode->key) {
    insertedNode->left = this->insert(insertedNode->left, key);
  }
  else {
    insertedNode->right = this->insert(insertedNode->right, key);
  }
  
  return this->balance(insertedNode);
}
