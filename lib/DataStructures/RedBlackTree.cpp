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

template <typename T> void RedBlackTree<T>::fixTree(Node<T> *node) {
  if (node->isNil() ||
      (node->parent->isRoot() && !node->right && !node->left)) {
    return;
  }

  auto uncle = this->uncle(node);
  if (uncle->color == Red) {
    node->parent->color = Black;
    uncle->color = Black;
    // TODO: make it iterable
    fixTree(node->parent);
  } else {
    if (isRight(node)) {
      leftRotate(node->parent);
    } else {
      // TODO: Color it
      auto grandfather = node->parent->parent;
      rightRotate(grandfather);
    }
  }
}

template <typename T> bool RedBlackTree<T>::isLeft(Node<T> *node) {
  return node->parent->left == node;
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
