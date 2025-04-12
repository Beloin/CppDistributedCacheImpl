#include <iostream>
#include <ctime>
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

  return 0;
}
