#pragma once

#include "../CrudRepository.h"

namespace Repository {
    template<typename StoredObject> requires IsSubclassOfObjectWithID<StoredObject>
    class InMemoryRepository : public CrudRepository<StoredObject> {
    public:
        ///Constructor
        explicit InMemoryRepository(vector<StoredObject> _data);

        ///Overloaded functions
        void create(const StoredObject &object) override;
        [[nodiscard]] vector<StoredObject> findAll() const override;
        [[nodiscard]] bool update(const StoredObject &oldObject, const StoredObject &newObject) override;
        [[nodiscard]] bool remove(const StoredObject &object) override;
    };
}