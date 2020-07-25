#include "ref_ptr.h"
#include "Object.h"
#include "Group.h"
#include "Auxiliary.h"
#include "observer_ptr.h"

#include <iostream>
#include <stdlib.h>
#include <vector>

mvsg::Group* createGroup() {
    mvsg::ref_ptr<mvsg::Group> group = new mvsg::Group;
    return group.release();
}

int main() {
    std::cout << "-- Before" << std::endl;

    mvsg::ref_ptr<mvsg::Group> global;

    {
        std::cout << "---- Start of block" << std::endl;

        mvsg::ref_ptr<mvsg::Group> group(createGroup());
        size_t pos = group->addChild(new mvsg::Node);

        std::cout << "Removing child to group" << std::endl;
        group->removeChild(pos);

        group->setObject("userdata", new mvsg::Object());
        group->setObject(10, new mvsg::Object());
        group->setObject(mvsg::Object::Key("list", 5), new mvsg::Object());

        global = group;

        

        std::cout << "---- End of block" << std::endl;

    }

    std::cout << " global->getObject(\"userdata\") = " << global->getObject("userdata") << std::endl;

    mvsg::observer_ptr<mvsg::Group> observer;

    //observer = global.get();
    observer = global;

    std::cout << "*******" << std::endl;
    {
        mvsg::ref_ptr<mvsg::Group> access = observer;
        std::cout << "++++ access.get() " << access.get() << " " << access->referenceCount() << std::endl;
        global = nullptr;
        std::cout << "++++ after global reset access.get() " << access.get() << " " << access->referenceCount() << std::endl;
    }
    std::cout << "******" << std::endl;


    std::cout << "-- After" << std::endl;

    std::cout << "size_of<mvsg::Object> " << sizeof(mvsg::Object) << std::endl;
    std::cout << "size_of<mvsg::Node> " << sizeof(mvsg::Node) << std::endl;
    std::cout << "size_of<mvsg::Grouo> " << sizeof(mvsg::Group) << std::endl;
    std::cout << "size_of<mvsg::Auxiliary> " << sizeof(mvsg::Auxiliary) << std::endl;


    system("pause");
    return 0;
}