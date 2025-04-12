#include "DataStructures/RedBlackTree.hpp"
#include <cstdlib>

template <typename T> void DataStructures::RedBlackTree<T>::insert(T *value) {}
template <typename T> void DataStructures::RedBlackTree<T>::insert(T value) {
  auto vv = (T*)malloc(sizeof(T));
  *vv = value;
  auto newNode = DataStructures::Node<T> { .value = vv };
}
