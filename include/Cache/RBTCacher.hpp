////////////////////////////////////////////////////////////////////////////////
// File:        RBTCacher.hpp
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////
#ifndef SRC_CACHE_RBTCACHER_H
#define SRC_CACHE_RBTCACHER_H
////////////////////////////////////////////////////////////////////////////////

#include "Cache/Cacher.hpp"
#include "DataStructures/RedBlackTree.hpp"
#include <string>
namespace Cache {

struct __rbtCacherNode {
  std::string key;
  std::string result;
};

//------------------------------------------------------------------------------

class RBTCacher : public Cacher {

public:
  RBTCacher() = default;
  ~RBTCacher() = default;

  virtual bool getString(const std::string &key, std::string &out) override;
  virtual bool setString(const std::string &key, std::string const &out) override;

private:
  DataStructures::RedBlackTree<__rbtCacherNode> data;
};

//------------------------------------------------------------------------------

} // namespace Cache
#endif /* SRC_CACHE_RBTCACHER_H */
