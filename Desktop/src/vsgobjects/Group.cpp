#include "Group.h"

#include <iostream>
#include <vector>

namespace mvsg {

    Group::Group() {
        std::cout << "Group::Group() " << this << std::endl;
    }

    Group::~Group() {
        std::cout << "Group::~Group() " << this << std::endl;
    }

}