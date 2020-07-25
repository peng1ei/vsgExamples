#pragma once

#include "Object.h"

#include <map>

namespace mvsg {

    /** Auxiliary provides extra Object data that is rarely used, and hooks for observers.*/
    class Auxiliary {
    public:
        Auxiliary();

        Object* getConnectedObject() {
            return _connectedObject;
        }

        void ref() const;
        void unref() const;
        void unref_nodelete() const;
        inline unsigned int referenceCount() const {
            return _referenceCount.load();
        }

        void setObject(const Object::Key &key, Object *object);
        Object* getObject(const Object::Key &key);
        const Object* getObject(const Object::Key &key) const;

        using ObjectMap = std::map<Object::Key, ref_ptr<Object>>;

        ObjectMap& getObjectMap() {
            return _objectMap;
        }
        const ObjectMap& getObjectMap() const {
            return _objectMap;
        }


    protected:
        virtual ~Auxiliary();

        void setConnectedObject(Object *object);


        friend class Object;

        Object* _connectedObject;
        mutable std::atomic_uint _referenceCount;
        
        ObjectMap _objectMap;
    };

}