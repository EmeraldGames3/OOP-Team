#include <iostream>
#include "../Controller/UserController/UserController.h"
#include "../Controller/ElectricScooterController/ElectricScooterController.h"

using std::string, std::cout, std::cin;
using namespace Controller;

namespace UI {
    class UserInterface {
    private:
        shared_ptr<UserController> userController;
        shared_ptr<ElectricScooterController> scooterController;

    public:
        UserInterface(shared_ptr<UserController> ctr1, shared_ptr<ElectricScooterController> ctr2);

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


    };
}