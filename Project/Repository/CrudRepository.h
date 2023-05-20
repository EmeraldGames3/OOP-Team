#pragma once
#include "../Domain/Domain.h"
#include <string>
#include <vector>

using std::string, std::vector;

namespace Repository {
    ///Template repository
    template<typename Type> requires IsSubclassOfObjectWithID<Type>
    class CrudRepository {
    protected:
        string fileName;
        vector<Type> data;

    public:
        ///Destructor
        virtual ~CrudRepository() = default;

        ///Add a new object
        virtual void create(const Type &object) = 0;

        ///Get all objects
        virtual vector<Type> findAll() const = 0;

        ///Update an object
        virtual bool update(const Type &oldObject, const Type &newObject) = 0;

        ///Remove an object
        virtual bool remove(const Type &object) = 0;

        void deleteAllData(){
            data = vector<Type>();
        }
    };
}