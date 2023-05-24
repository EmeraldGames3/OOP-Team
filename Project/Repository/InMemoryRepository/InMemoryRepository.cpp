#include "InMemoryRepository.h"
#include <fstream>

/// Constructor
/// @throws invalid_argument if the received data is insufficient
template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>
Repository::InMemoryRepository<StoredObject>::InMemoryRepository(vector<StoredObject> _data) {
    if(_data.size() < 10)
        throw std::invalid_argument("Initialize the repository with a minimum of 10 objects");

    for(const auto &it : _data){
        this->data.push_back(make_shared<StoredObject>(it));
    }
}

///Add a new object to the repository
template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>void
Repository::InMemoryRepository<StoredObject>::create(const StoredObject &object) {
    this->data.push_back(make_shared<StoredObject>(object));
}

///Returns a vector with all the data in the repository
template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>vector<StoredObject>
Repository::InMemoryRepository<StoredObject>::findAll() const {
    vector<StoredObject> returnVector{};

    for (const auto &ptr : this->data) {
        auto *obj = dynamic_cast<StoredObject*>(ptr.get());
        if (obj) {
            returnVector.push_back(*obj);
        }
    }

    return returnVector;
}

///Update an object from the data base
///@return true if the object was found and updated, false otherwise
template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>bool
Repository::InMemoryRepository<StoredObject>::update(const StoredObject &oldObject, const StoredObject &newObject) {
    for (auto &it: this->data) {
        if (it->getId() == oldObject.getId()) {
            it = make_unique<StoredObject>(newObject);
            return true;
        }
    }
    return false;
}

///Remove an object from the data base
///@return true if the object was successfully removed, false otherwise
template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>bool
Repository::InMemoryRepository<StoredObject>::remove(const StoredObject &object) {
    for (int i = 0; i < this->data.size(); i++) {
        if (this->data[i]->getId() == object.getId()) {
            this->data.erase(this->data.begin() + i);
            return true;
        }
    }
    return false;
}

//Instantiate the templated class to allow the compiler to generate the necessary code
template class Repository::InMemoryRepository<ElectricScooter>;
template class Repository::InMemoryRepository<User>;
template class Repository::InMemoryRepository<Manager>;
template class Repository::InMemoryRepository<Client>;