#include "UI/UserInterface.h"
#include <memory>
#include "Tests/TestAll.h"
#include <fstream>

using namespace UI;
using namespace std;

int main() {
    testAll();

    if (UserInterface::firstPrompt()) {
        //Data is saved
        CSVFileRepository<Client> clientRepo("Data/ClientDatabase");
        CSVFileRepository<Manager> managerRepo("Data/ManagerDatabase");
        CSVFileRepository<ElectricScooter> scooterRepo("Data/ScooterDatabase");

        ElectricScooterController electricScooterController(
                make_shared<CSVFileRepository<ElectricScooter>>(scooterRepo));
        UserController userController(make_shared<CSVFileRepository<Client>>(clientRepo),
                                      make_shared<CSVFileRepository<Manager>>(managerRepo));

        UserInterface userInterface(make_shared<UserController>(userController),
                                    make_shared<ElectricScooterController>(electricScooterController));

        userInterface.mainMenu();
    } else {
        vector<Client> clients;
        vector<Manager> managers;
        vector<ElectricScooter> scooters;

        ///
        {
            ifstream file("Data/ClientDatabase");
            if(!file.is_open())
                throw invalid_argument("File not found");

            string line;
            std::getline(file, line); //Read the line with the format

            Client temp; // I have to use this because c++ does not let me override static functions
            while (std::getline(file, line)) {
                clients.push_back(Client::convertFromStr(line));
            }

            file.close();
        }
        ///
        {
            ifstream file("Data/ManagerDatabase");
            if(!file.is_open())
                throw invalid_argument("File not found");

            string line;
            getline(file, line); //Read the line with the format

            while (std::getline(file, line)) {
                managers.push_back(Manager::convertFromStr(line));
            }

            file.close();
        }
        ///
        {
            ifstream file("Data/ScooterDatabase");
            if(!file.is_open())
                throw invalid_argument("File not found");

            string line;
            getline(file, line); //Read the line with the format

            while (std::getline(file, line)) {
                scooters.push_back(ElectricScooter::convertFromStr(line));
            }

            file.close();
        }
        ///

        InMemoryRepository<Client> clientRepo(clients);
        InMemoryRepository<Manager> managerRepo(managers);
        InMemoryRepository<ElectricScooter> scooterRepo(scooters);

        ElectricScooterController electricScooterController(
                make_shared<InMemoryRepository<ElectricScooter>>(scooterRepo));
        UserController userController(make_shared<InMemoryRepository<Client>>(clientRepo),
                                      make_shared<InMemoryRepository<Manager>>(managerRepo));

        UserInterface userInterface(make_shared<UserController>(userController),
                                    make_shared<ElectricScooterController>(electricScooterController));

        userInterface.mainMenu();
    }

    return 0;
}