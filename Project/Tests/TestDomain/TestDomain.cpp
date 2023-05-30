#include "TestDomain.h"
#include "TestDate/TestDate.h"
#include "TestUser/TestUser.h"
#include "TestElectricScooter/TestElectricScooter.h"
#include "TestUser/TestClient.h"

void testDomain() {
    testDate();
    testUser();
    testClient();
    testElectricScooter();
}