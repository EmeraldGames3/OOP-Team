#pragma once

#include "../CrudRepository.h"

namespace Repository {
    template<typename Type> requires IsSubclassOfObjectWithID<Type>
    class InMemoryRepository : public CrudRepository<Type> {
    public:

    };
}