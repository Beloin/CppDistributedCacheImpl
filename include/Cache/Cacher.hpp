////////////////////////////////////////////////////////////////////////////////
// File:        Cacher.hpp
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////
#ifndef INCLUDE_CACHE_CACHER_H
#define INCLUDE_CACHE_CACHER_H
////////////////////////////////////////////////////////////////////////////////

#include <string>
namespace Cache {

//------------------------------------------------------------------------------

class Cacher {

public:
  virtual bool getString(const std::string &key, std::string &out) = 0;
  virtual bool setString(const std::string &key, const std::string &out) = 0;
};

//------------------------------------------------------------------------------

} // namespace Cache
#endif /* INCLUDE_CACHE_CACHER_H */
