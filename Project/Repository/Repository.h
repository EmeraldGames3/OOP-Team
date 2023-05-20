#pragma once

#include "CrudRepository.h"
#include "InMemoryRepository/InMemoryRepository.h"
#include "CSV-FileRepository/CSV-FileRepository.h"

namespace Repository {
    template<typename Type> requires IsSubclassOfObjectWithID<Type> class CrudRepository;
    template<typename Type> requires IsSubclassOfObjectWithID<Type> class InMemoryRepository;
    template<typename Type> requires IsSubclassOfObjectWithID<Type> class CSVFileRepository;
}