#include "Cache/MapCacher.hpp"

bool Cache::MapCacher::setString(const std::string &key,
                                 std::string const &out) {
  cache[key] = out;
  return true;
}

bool Cache::MapCacher::getString(const std::string &key, std::string &out) {
  if (cache.find(key) == cache.end()) {
    return false;
  }

  out = cache.at(key);
  return true;
}
