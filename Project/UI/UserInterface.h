#pragma once
#include <iostream>
#include "../Controller/Controller.h"

using std::string, std::cout, std::cin;
using namespace Controller;

namespace UI {
    class UserInterface {
    private:
        shared_ptr<UserController> userController;
        shared_ptr<ElectricScooterController> scooterController;

    public:
        UserInterface(shared_ptr<UserController> ctr1, shared_ptr<ElectricScooterController> ctr2);

    };
}