SET(APPLICATION_NAME vsgobjects)

SET(HEADERS
#    Object.hpp
#    Node.hpp
#    Group.hpp
#    ref_ptr.hpp
 "ref_ptr.h" "Object.h" "Node.h" "Group.h" "Auxiliary.h" "observer_ptr.h")

SET(SOURCES
 #   Object.cpp
 #   Node.cpp
 #   Group.cpp
    vsgobjects.cpp
 "Object.cpp" "Node.cpp" "Group.cpp" "Auxiliary.cpp")

INCLUDE_DIRECTORIES(${OPENTHREADS_INCLUDE_DIR} ${OSG_INCLUDE_DIR})

LINK_DIRECTORIES(${OSG_LIB_DIR})

ADD_EXECUTABLE(${APPLICATION_NAME} ${HEADERS} ${SOURCES})

TARGET_LINK_LIBRARIES(${APPLICATION_NAME} ${OSG_LIBRARIES} ${OSGVIEWER_LIBRARIES} ${OSGUTIL_LIBRARIES} ${OSGDB_LIBRARIES} ${OSGGA_LIBRARIES} ${OPENTHREADS_LIBRARIES})