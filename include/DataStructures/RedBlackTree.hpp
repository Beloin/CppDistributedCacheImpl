////////////////////////////////////////////////////////////////////////////////
// File:        RedBlackTree.hpp
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////
#ifndef INCLUDE_DATASTRUCTURES_REDBLACKTREE_H
#define INCLUDE_DATASTRUCTURES_REDBLACKTREE_H
////////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <optional>

namespace DataStructures {

typedef std::uint8_t Color;

template <typename T> struct Node {
  Color color;
  T *value;

  Node *parent;

  Node *right;
  Node *left;

  bool isNil() { return !value; }
  bool isRoot() { return !parent; }
};

//------------------------------------------------------------------------------

// TODO: Maybe create an async implementation?
// Must be comparable, maybe something like SearchableNode { key, value }
template <typename T> class RedBlackTree {

public:
  const static Color Red = 0;
  const static Color Black = 0;

  RedBlackTree() = default;
  ~RedBlackTree() = default;

  void insert(T *value);
  void insert(T value);

  Node<T> find(T *value);

private:
  Node<T> root{.color = Black, .value = nullptr};

  Node<T> *uncle(Node<T> *node);

  void fixTree(Node<T> *node);
  void leftRotate(Node<T> *node);
  void rightRotate(Node<T> *node);

  bool isLeft(Node<T> *node);
  bool isRight(Node<T> *node) { return !isLeft(node); }

  void clear(Node<T> *node);
};

//------------------------------------------------------------------------------

} // namespace DataStructures
#endif /* INCLUDE_DATASTRUCTURES_REDBLACKTREE_H */
