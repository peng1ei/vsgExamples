#pragma once

#include <atomic>
#include <string>

#include "ref_ptr.h"

namespace mvsg {

    // forward declare
    class Auxiliary;

    class Object {
    public:
        Object();

        void ref() const;

        void unref() const;

        void unref_nodelete() const;

        inline unsigned int referenceCount() const {
            return _referenceCount.load();
        }

        struct Key {
            Key(const char* in_name) : name(in_name), index(0) {}
            Key(const std::string &in_name) : name(in_name), index(0) {}

            Key(const char* in_name, int in_index) : name(in_name), index(in_index) {}
            Key(const std::string& in_name, int in_index) : name(in_name), index(in_index) {}

            Key(int in_index) : index(in_index) {}

            bool operator < (const Key& rhs) const {
                if (name < rhs.name) return true;
                if (name > rhs.name) return false;

                return (index < rhs.index);
            }
 
            std::string name;
            int index;
        };

#if 0
        template<typename T>
        void setValue(const Key &key, const T &value) {}
        template<typename T>
        bool getValue(const Key& key, T& value) { return false; }
        template<typename T>
        bool getVaule(const Key &key, const T &value) const { return false; }
#endif

        void setObject(const Key &key, Object *object);
        Object* getObject(const Key& key);
        const Object* getObject(const Key& key) const;

        Auxiliary* getOrCreateAuxiliary();
        Auxiliary* getAuxiliary() {
            return _auxiliary;
        }
        const Auxiliary* getAuxiliary() const {
            return _auxiliary;
        }


    protected:
        virtual ~Object();

        mutable std::atomic_uint _referenceCount;

        Auxiliary* _auxiliary;
    };

}
