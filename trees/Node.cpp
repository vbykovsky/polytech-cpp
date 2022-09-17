#include "Node.hpp"

void Node::print(const char name[] = "") {
  using namespace std;

  cout <<
    (strlen(name) > 0 ? name : "Node")
    << "(" << this->key << "): "
    << "left(" << (this->left != nullptr ? this->left->key : -1) << ") "
    << "right(" << (this->right != nullptr ? this->right->key : -1) << ")" << endl;
}