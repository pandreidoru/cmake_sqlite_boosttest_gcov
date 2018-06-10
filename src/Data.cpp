//
// Created by Andrei - Doru Pata on 03/06/18.
//
#include <Data.hpp>

namespace persist {
  std::ostream& operator<<(std::ostream& os, const Data& data) {
    return os << "id = " << data.id_ << " name = " << data.name_;
  }
} // namespace persist