//
// Created by Andrei - Doru Pata on 03/06/18.
//
#include <Data.hpp>

namespace persist {
  std::ostream& operator<<(std::ostream& os, const Data& data) {
    if (!data.member1_.empty()) {
      os << data.member1_ << " ";
    }
    
    if (!data.member2_.empty()) {
      os << data.member2_ << " ";
    }
    
    os << data.id_;
    
    return os;
  }
} // namespace persist