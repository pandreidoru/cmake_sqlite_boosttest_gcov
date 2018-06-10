#include <iostream>
#include <Data.hpp>

int main() {
  auto data = persist::Data{ 1, "Data 1" };
  
  std::cout << data << std::endl;
  
  return 0;
}