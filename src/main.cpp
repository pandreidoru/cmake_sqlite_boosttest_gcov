#include <iostream>
#include <Data.hpp>

int main() {
  auto data = persist::Data{ 1, "Member 1", "Member 2" };
  
  std::cout << "Hello, " << data << "!" << std::endl;
  
  return 0;
}