#pragma once

#include "ref_ptr.h"
#include "Node.h"

#include <vector>

namespace mvsg {

    class Group : public Node {
    public:
        Group();

        std::size_t addChild(Node* child) {
            std::size_t pos = _children.size();
            _children.push_back(child);
            return pos;
        }

        void removeChild(std::size_t pos) {
            _children.erase(_children.begin() + pos);
        }

        Node* getChild(std::size_t pos) {
            return _children[pos].get();
        }
        const Node* getChild(std::size_t pos) const {
            return _children[pos].get();
        }

        std::size_t getNumChildren() const {
            return _children.size();
        }

        using Children = std::vector<ref_ptr<Node>>;

        Children& getChildren() { return _children; }
        const Children& getChildren() const { return _children; }

    protected:
        virtual ~Group();

        Children _children;
    };

}