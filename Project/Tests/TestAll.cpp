#include "TestAll.h"
#include "TestDomain/TestDomain.h"
#include "TestRepository/TestRepository.h"
#include "TestController/TestController.h"

void testAll(){
    testDomain();
    testRepository();
    testController();
}