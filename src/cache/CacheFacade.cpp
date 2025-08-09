#include "CacheFacade.hpp"

using Cache::CacheFacade;

bool CacheFacade::getString(const std::string &key, std::string &out) {
  return cacher.getString(key, out);
}

bool CacheFacade::setString(const std::string &key, std::string const &out) {
  return cacher.setString(key, out);
}
