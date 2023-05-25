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

        void saveMethodMeniu();

        void mainMenu();

        void managerMenu();

        void managerLogIn();

        void managerRegistration();

        void clientMenu();

        void clientLogIn();

        void clientRegistration();

        void showAll();

        void updateInfo();

        void updateId(const string &id);

        void updateModel(const string &id);

        void updateDate(const string &id);

        void updateMileage(const string &id);

        void updateLocation(const string &id);

        void updateCondition(const string &id);

        void managerUI();

        void clientUI();

        static bool firstPrompt();
    };
}