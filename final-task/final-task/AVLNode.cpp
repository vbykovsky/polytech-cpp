#include "AVLNode.hpp"

AVLNode::AVLNode(int value) : Node(value), height(1) {
}

void AVLNode::updateValues() {
  auto leftCount = 0;
  auto leftHeight = 0;

  if (left != nullptr) {
    leftCount = left->size;
    leftHeight = left->height;
  }

  auto rightCount = 0;
  auto rightHeight = 0;

  if (right != nullptr) {
    rightCount = right->size;
    rightHeight = right->height;
  }

  size = leftCount + rightCount + 1;

  height = std::max(leftHeight, rightHeight) + 1;
}

int AVLNode::balanceFactor() {
  auto leftHeight = left != nullptr ? left->height : 0;
  auto rightHeight = right != nullptr ? right->height : 0;

  return leftHeight - rightHeight;
}

AVLNode* AVLNode::leftRotate() {
  AVLNode* rightTmp = right;

  right = right->left;
  rightTmp->left = this;

  this->updateValues();
  rightTmp->updateValues();

  return rightTmp;
}

AVLNode* AVLNode::rightRotate() {
  AVLNode* leftTmp = left;
  left = left->right;
  leftTmp->right = this;

  this->updateValues();
  leftTmp->updateValues();

  return leftTmp;
}