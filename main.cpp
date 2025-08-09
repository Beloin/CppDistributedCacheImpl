#include "Cache/Cacher.hpp"
#include "Cache/MapCacher.hpp"
#include "src/cache/CacheFacade.hpp"
#include <iostream>
#include <ctime>
#include <ostream>
#include <unistd.h>

int main (int argc, char *argv[]) {
  
  std::cout << "Hello World" << std::endl;

  std::time_t now = std::time(nullptr);
  std::cout << "Current Time: " << std::asctime(std::localtime(&now));

  const char* user = getlogin();
  if (user != nullptr) {
      std::cout << "Logged User: " << user << std::endl;
  } else {
      std::cerr << "Failed to get logged user" << std::endl;
  }

  // TODO: free this later
  Cache::CacheFacade facade{*(new Cache::MapCacher{})};

  facade.setString("John", "YES");

  std::string out = "jair";
  facade.getString("John", out);
  std::cout << "out: " << out << std::endl;

  return 0;
}
