#include "Tree.hpp"

int Tree::pushNode(Node* node) {
  this->nodesCount += 1;

  this->nodes[this->nodesCount - 1] = node;

  return nodesCount - 1;
}

int Tree::popNode(Node* node) {
  int nodeIndex = -1;

  for (int i = 0; i < this->nodesCount; i++) {
    if (this->nodes[i] == node) {
      nodeIndex = i;
    }

    if (nodeIndex != -1) {
      this->nodes[i] = this->nodes[i + 1];
    }
  }

  this->nodesCount -= 1;

  return nodeIndex;
}

Node* Tree::find(int key) {
  Node* node = this->root;

  while (node != nullptr && node->key != key) {
    if (key > node->key) {
      node = node->right;
    }
    else {
      node = node->left;
    }
  }

  return node;
}

Node* Tree::findLastNode(int key) {
  Node* node = this->root;
  Node* lastNode = nullptr;

  while (node != nullptr && node->key != key) {
    lastNode = node;

    if (key > node->key) {
      node = node->right;
    }
    else {
      node = node->left;
    }
  }

  return node == nullptr ? lastNode : node;
}

Node* Tree::min() {
  return this->minFrom(this->root);
}

Node* Tree::minFrom(Node* fromNode) {
  Node* node = fromNode;

  while (node->left != nullptr) {
    node = node->left;
  }

  return node;
}

Node* Tree::max() {
  return this->maxFrom(this->root);
}

Node* Tree::maxFrom(Node* fromNode) {
  Node* node = fromNode;

  while (node->right != nullptr) {
    node = node->right;
  }

  return node;
}

Node* Tree::findNext(int key) {
  Node* node = this->find(key);

  return node != nullptr ? this->findNext(node) : nullptr;
}

Node* Tree::findNext(Node* node) {
  if (node->right != nullptr) {
    return this->minFrom(node->right);
  }

  Node* nextNode = node->parent;

  while (nextNode != nullptr && nextNode->left != node) {
    node = nextNode;
    nextNode = node->parent;
  }

  return nextNode;
}

void Tree::insert(int key, Node* insertedNode) {
  Node* lastNode = findLastNode(key);

  if (lastNode->key == key) {
    insertedNode = nullptr;

    return;
  }

  insertedNode->key = key;
  insertedNode->parent = lastNode;

  if (insertedNode->key > lastNode->key) {
    lastNode->right = insertedNode;
  }
  else {
    lastNode->left = insertedNode;
  }

  this->pushNode(insertedNode);
}

Node* Tree::remove(int key) {
  return this->remove(this->find(key));
}

Node* Tree::remove(Node* node) {
  Node* parent = node->parent;

  if (node->left == nullptr && node->right == nullptr) {
    node->parent = nullptr;
    
    if (parent->left == node) {
      parent->left = nullptr;
    }

    if (parent->right == node) {
      parent->right = nullptr;
    }

    this->popNode(node);

    return node;
  }

  if (node->left == nullptr || node->right == nullptr) {
    Node* child = node->left == nullptr ? node->right : node->left;

    node->parent = nullptr;

    if (parent->left == node) {
      parent->left = child;
    }

    if (parent->right == node) {
      parent->right = child;
    }

    this->popNode(node);

    return node;
  }

  Node* minFromRight = this->minFrom(node->right);
  node->key = minFromRight->key;

  return this->remove(minFromRight);
}