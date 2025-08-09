#include "DataStructures/RedBlackTree.hpp"
#include <cstddef>
#include <cstdlib>

using namespace DataStructures;

template <typename T> void fixTree(Node<T> *node);

template <typename T> void DataStructures::RedBlackTree<T>::insert(T *value) {
  auto newNode = DataStructures::Node<T>{.value = value, .color = Red};

  Node<T> *pivot = this->root;
  if (pivot == nullptr) {
    root = newNode;
    root.color = Black;
    return;
  }

  Node<T> *last;
  while (pivot != nullptr) {
    last = pivot;
    if (*(pivot->value) < *value) {
      pivot = pivot->right;
    } else {
      pivot = pivot->left;
    }
  }

  if (*(last->value) < *value) {
    last->right = newNode;
  } else {
    last->left = newNode;
  }
  newNode.parent = last;

  if (newNode.parent->color == Red) {
    fixTree(newNode);
  }
}

template <typename T> void DataStructures::RedBlackTree<T>::insert(T value) {
  T *copiedValue = (T *)malloc(sizeof(T));
  *copiedValue = value;
  insert(copiedValue);
}

template <typename T> Node<T> *RedBlackTree<T>::uncle(Node<T> *node) {
  auto parent = node->parent;
  if (!parent || !(parent->parent)) {
    return nullptr;
  }
  auto grandfather = parent->parent;
  if (grandfather->left == parent) {
    return grandfather->right;
  }

  return grandfather->left;
}

// TODO: Create the cases separated instead of this
template <typename T> void RedBlackTree<T>::fixTree(Node<T> *node) {
  if (node->isNil() ||
      (node->parent->isRoot() && !node->right && !node->left)) {
    return;
  }

  if (node->isRoot()) {
    node->color = Black;
    return;
  }

  auto uncle = this->uncle(node);
  if (uncle != nullptr && uncle->color == Red) {
    node->parent->color = Black;
    uncle->color = Black;
    auto grandfather = node->parent->parent;
    grandfather->color = Red;
    fixTree(grandfather);
  } else {
    if (isRight(node) && isLeft(node->parent)) {
      leftRotate(node->parent);
      node = node->left; // Becomes the former parent
    } else if (isLeft(node) && isRight(node->parent)) {
      rightRotate(node->parent);
      node = node->right; // Becomes the former parent
    }

    node->parent->color = Black;
    auto grandparent = node->parent->parent;
    grandparent->color = Red;

    if (isLeft(node) && isLeft(node->parent)) {
      rightRotate(grandparent);
    } else {
      leftRotate(grandparent);
    }
  }
}

template <typename T> bool RedBlackTree<T>::isLeft(Node<T> *node) {
  return node->parent->left == node;
}

template <typename T> bool RedBlackTree<T>::isRight(Node<T> *node) {
  return node->parent->right == node;
}

template <typename T> void RedBlackTree<T>::leftRotate(Node<T> *node) {
  auto right = node->right;
  node->right = right->left;

  if (right->left != nullptr) {
    right->left->parent = node;
  }

  right->parent = node->parent;

  if (node->parent == nullptr) { // Root
    root = right;
  } else if (isLeft(node)) {
    node->parent->left = right;
  } else {
    node->parent->right = right;
  }

  right->left = node;
  node->parent = right;
}

template <typename T> void RedBlackTree<T>::rightRotate(Node<T> *node) {
  auto left = node->left;
  node->left = left->right;

  if (left->right != nullptr) {
    left->right->parent = node;
  }

  left->parent = node->parent;

  if (node->parent == nullptr) { // Root
    root = left;
  } else if (isLeft(node)) {
    node->parent->left = left;
  } else {
    node->parent->right = left;
  }

  left->right = node;
  node->parent = left;
}

template <typename T> Node<T> RedBlackTree<T>::find(T *value) {
  Node<T> *current = &root;

  while (current) {
    if (*current->value == *value) {
      break;
    }

    if (*(current->value) > *(value)) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  // This creates a copy of the node to be visualized externally
  return *current;
}
