////////////////////////////////////////////////////////////////////////////////
// File:        MapCacher.hpp
// Author:      Beloin Rodrigues
////////////////////////////////////////////////////////////////////////////////
#ifndef INCLUDE_CACHE_MAPCACHER_H
#define INCLUDE_CACHE_MAPCACHER_H
////////////////////////////////////////////////////////////////////////////////

#include "Cache/Cacher.hpp"
#include <unordered_map>
namespace Cache {

//------------------------------------------------------------------------------

class MapCacher : public Cacher {

public:
  MapCacher() = default;
  ~MapCacher() = default;

  bool getString(const std::string &key, std::string &out) override;
  bool setString(const std::string &key, std::string const &out) override;

private:
  std::unordered_map<std::string, std::string> cache;
};

//------------------------------------------------------------------------------

} // namespace Cache
#endif /* INCLUDE_CACHE_MAPCACHER_H */
