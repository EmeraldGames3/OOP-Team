#include "TestRepository.h"
#include "TestInMemoryRepository/TestInMemoryRepository.h"
#include "TestCSVFileRepository/TestCSVFileRepository.h"

void testRepository() {
    testInMemoryRepository();
    testCSVFileRepository();
}