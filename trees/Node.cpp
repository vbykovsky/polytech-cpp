#include "Node.hpp"

void Node::print(const char name[] = "") {
  using namespace std;

  cout <<
    (strlen(name) > 0 ? name : "Node")
    << "(" << this->key << "): "
    << "left(" << (this->left != nullptr ? this->left->key : -1) << ") "
    << "right(" << (this->right != nullptr ? this->right->key : -1) << ")" << endl;
}

bool Node::isNotDefined(){
  return this->key == -1 && this->left == nullptr && this->right == nullptr && this->parent == nullptr;
}

int getNodeHeight(Node* node) {
  return node != nullptr ? node->height : 0;
}

int getNodeBalanceFactor(Node* node) {
  return getNodeHeight(node->right) - getNodeHeight(node->left);
}

int restoreNodeHeight(Node* node) {
  node->height = std::max(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;

  return node->height;
}