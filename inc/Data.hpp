//
// Created by Andrei - Doru Pata on 01/06/18.
//
#pragma once

#include <odb/core.hxx>
#include <ostream>

namespace persist {
#pragma db object
  struct Data {
    friend class odb::access;

#pragma db id auto
    unsigned long int id_;
    std::string name_;
    
    friend std::ostream& operator<<(std::ostream&, const Data&);
  };
} // namespace persist