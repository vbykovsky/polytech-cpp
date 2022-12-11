#include "AVLTree.hpp"

AVLTree::AVLTree() {
}

AVLTree::~AVLTree() {
  clear();
}

int AVLTree::find(int value) const {
  AVLNode* direct = root;
  int idx = 0;

  while (direct != nullptr && direct->value != value) {
    if (direct->value > value) {
      direct = direct->left;
    }
    else {
      idx += (direct->left ? direct->left->size : 0) + 1;
      direct = direct->right;
    }
  }

  if (direct == nullptr) {
    return -1;
  }

  return idx + (direct->left ? direct->left->size : 0);
}

void AVLTree::insert(int value) {
  AVLNode** indirect = &root;
  std::vector<AVLNode**> path;

  while (*indirect != nullptr) {
    path.push_back(indirect);

    if ((*indirect)->value > value) {
      indirect = &((*indirect)->left);
    }
    else {
      indirect = &((*indirect)->right);
    }
  }

  *indirect = new AVLNode(value);
  path.push_back(indirect);

  balance(path);
  size++;
}

void AVLTree::erase(int value) {
  AVLNode** indirect = &root;
  std::vector<AVLNode**> path;

  while (*indirect != nullptr && (*indirect)->value != value) {
    path.push_back(indirect);

    if ((*indirect)->value > value) {
      indirect = &((*indirect)->left);
    }
    else {
      indirect = &((*indirect)->right);
    }
  }

  if (*indirect == nullptr) {
    return;
  }
  else {
    path.push_back(indirect);
  }

  size_t index = path.size();

  if ((*indirect)->left == nullptr && (*indirect)->right == nullptr) {
    delete* indirect;
    *indirect = nullptr;
    path.pop_back();
  }
  else if ((*indirect)->right == nullptr) {
    AVLNode* toRemove = *indirect;

    (*indirect) = (*indirect)->left;
    delete toRemove;

    path.pop_back();
  }
  else {
    AVLNode** successor = &((*indirect)->right);

    while ((*successor)->left != nullptr) {
      path.push_back(successor);
      successor = &((*successor)->left);
    }

    if (*successor == (*indirect)->right) {
      (*successor)->left = (*indirect)->left;

      AVLNode* toRemove = *indirect;
      *indirect = *successor;
      delete toRemove;
    }

    else {
      AVLNode* tmp = *path.back(), * suc = *successor;

      tmp->left = (*successor)->right;
      suc->left = (*indirect)->left;
      suc->right = (*indirect)->right;

      delete* indirect;
      *indirect = suc;
      path[index] = &(suc->right);
    }
  }

  balance(path);
  size--;
}

void AVLTree::clear() {
  std::vector<Node*> stack;

  if (root != nullptr) {
    stack.push_back(root);
  }

  while (!stack.empty()) {
    Node* node = stack.back();
    stack.pop_back();

    if (node->left != nullptr) {
      stack.push_back(node->left);
    }

    if (node->right != nullptr) {
      stack.push_back(node->right);
    }

    size--;
    delete node;
  }

  root = nullptr;
}

int AVLTree::getSize() const {
  return size;
}

bool AVLTree::isEmpty() const {
  return size == 0;
}

void AVLTree::balance(std::vector<AVLNode**> path) {
  reverse(path.begin(), path.end());

  for (auto indirect : path) {
    (*indirect)->updateValues();

    // left - left
    if ((*indirect)->balanceFactor() >= 2 && (*indirect)->left->balanceFactor() >= 1) {
      *indirect = (*indirect)->rightRotate();
    }
    // left - right
    else if ((*indirect)->balanceFactor() >= 2) {
      (*indirect)->left = (*indirect)->left->leftRotate();
      *indirect = (*indirect)->rightRotate();
    }
    // right - right
    else if ((*indirect)->balanceFactor() <= -2 && (*indirect)->right->balanceFactor() <= -1) {
      *indirect = (*indirect)->leftRotate();
    }
    // right - left
    else if ((*indirect)->balanceFactor() <= -2) {
      (*indirect)->right = ((*indirect)->right)->rightRotate();
      *indirect = (*indirect)->leftRotate();
    }
  }
}

void AVLTree::display() {
  std::cout << std::endl;

  if (root != nullptr) {
    display(root);
  }
  else {
    std::cout << "Empty";
  }

  std::cout << std::endl;
}

void AVLTree::display(AVLNode* cur, int depth, int state /* (0: root, 1: left, 2: right) */) {
  if (cur->right) {
    display(cur->right, depth + 1, 2);
  }

  for (int i = 0; i < depth; i++) {
    std::cout << "     ";
  }

  std::cout << "|----";

  std::cout << "[" << cur->value << "]" << std::endl;

  if (cur->left) {
    display(cur->left, depth + 1, 1);
  }
}

void AVLTree::printBalancedOrder() {
  std::vector<AVLNode*> order;

  order.push_back(root);

  for (int i = 0; i < size; i++) {
    if (order[i]->left != nullptr) {
      order.push_back(order[i]->left);
    }
    if (order[i]->right != nullptr) {
      order.push_back(order[i]->right);
    }
  }

  for (auto node: order) {
    std::cout << node->value << " ";
  }
}