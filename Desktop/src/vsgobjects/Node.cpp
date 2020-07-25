#include "Node.h"

#include <iostream>
#include <vector>

namespace mvsg {

    Node::Node() {
        std::cout << "Node::Node() " << this << std::endl;
    }

    Node::~Node() {
        std::cout << "Node::~Node() " << this << std::endl;
    }

}