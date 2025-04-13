#include "DataStructures/RedBlackTree.hpp"
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

  }
}
