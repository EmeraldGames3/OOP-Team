#pragma once

#include "../Domain/Domain.h"
#include <string>
#include <vector>

using std::string, std::vector;

namespace Repository {
    ///Template repository
    template<typename StoredObject> requires IsSubclassOfObjectWithID<StoredObject>
    class CrudRepository {
    protected:
        string fileName;
        vector<StoredObject> data;

    public:
        ///Destructor
        virtual ~CrudRepository() = default;

        ///Add a new object
        virtual void create(const StoredObject &object) = 0;

        ///Get all objects
        virtual vector<StoredObject> findAll() const = 0;

        ///Update an object
        virtual bool update(const StoredObject &oldObject, const StoredObject &newObject) = 0;

        ///Remove an object
        virtual bool remove(const StoredObject &object) = 0;

        void deleteAllData() {
            data = vector<StoredObject>();
        }
    };
}