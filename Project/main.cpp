#include "UI/UserInterface.h"
#include <memory>
#include "Tests/TestAll.h"

using namespace UI;

int main() {
    testAll();

//    shared_ptr<ClientRepository> repo1 = make_shared<ClientRepository>();
//    shared_ptr<ManagerRepository> repo2 = make_shared<ManagerRepository>();
//    shared_ptr<ElectricScooterRepository> repo3 = make_shared<ElectricScooterRepository>();
//    shared_ptr<UserController> controllerU = make_shared<UserController>(repo1, repo2);
//    shared_ptr<ElectricScooterController> controllerS = make_shared<ElectricScooterController>(repo3);

    shared_ptr<UserController> controllerU = make_shared<UserController>();
    shared_ptr<ElectricScooterController> controllerS = make_shared<ElectricScooterController>();
    UserInterface ui(controllerU, controllerS);
    ui.mainMenu();

    return 0;
}
