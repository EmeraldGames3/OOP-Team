#pragma once

#include "../CrudRepository.h"

namespace Repository {
    template<typename StoredObject> requires IsSubclassOfObjectWithID<StoredObject>
    class CSVFileRepository : public CrudRepository<StoredObject> {
    private:
        ///Used by the update function
        void writeToFile();

    public:
        ///Constructor
        explicit CSVFileRepository(const string &file);

        ///Override the create function
        void create(const StoredObject &storedObject) override;

        ///Override the findAll function
        [[nodiscard]] vector<StoredObject> findAll() const override;

        ///Override the update function
        [[nodiscard]] bool update(const StoredObject &oldObject, const StoredObject &newObject) override;

        ///Override the remove function
        [[nodiscard]] bool remove(const StoredObject &storedObject) override;
    };
}