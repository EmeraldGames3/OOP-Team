#include "UserInterface.h"

using namespace UI;

UserInterface::UserInterface(shared_ptr<UserController> ctr1, shared_ptr<ElectricScooterController> ctr2) {
    userController = ctr1;
    scooterController = ctr2;
}

void UserInterface::mainMenu() {
    int choice;
    cout << endl;
    cout << "------------------------ WELCOME TO SCOOTERS~RENTAL.COM ------------------------" << endl;
    cout << endl;
    cout << "~ Continue as ~" << endl;
    cout << "1. Manager" << endl;
    cout << "2. Client" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice and press enter: " << endl;
    cout << ">";

    cin >> choice;
    switch (choice) {
        case 1:
            managerMenu();
            break;
        case 2:
            clientMenu();
            break;
        case 3: {
            cout << "\n~~~~~~GOOD BYE!~~~~~~\n";
            break;
        }

        default: {
            cout << "\nInvalid choice...\n";
            cout << "Try again\n";
            cin.clear();
            cin.ignore();
            mainMenu();
            break;
        }
    }
}

void UserInterface::managerMenu() {
    bool running = true;
    string option;
    while (running) {
        int choice;
        cout << "-----------------------  SCOOTERS~RENTAL.COM -----------------------" << endl;
        cout << "1. Register" << endl;
        cout << "2. Log in" << endl;
        cout << "3. Back" << endl;
        cout << "Enter your choice and press enter: " << endl;
        cout << ">";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << endl;

                try {
                    managerRegistration();
                }
                catch (exception &e) {
                    cout << "Username is already taken" << endl;
                    managerRegistration();
                }
                cout << endl;
                cout << "Would you like to log out? (yes / no)\n";
                cout << ">";
                cin >> option;
                if (option == "yes")
                    running = false;
                if (option == "no") {
                    option.clear();
                    managerUI();
                }

                break;
            case 2:
                cout << endl;
                try {
                    managerLogIn();
                }
                catch (exception &e) {
                    cout << "Something went wrong" << endl;
                    cout << "Incorrect username or password" << endl;
                    managerLogIn();
                }
                cout << endl;
                cout << "Would you like to log out? (yes / no)\n";
                cout << ">";
                cin >> option;
                if (option == "yes")
                    running = false;
                if (option == "no") {
                    option.clear();
                    managerUI();
                }
                break;
            case 3:
                running = false;
                mainMenu();
                break;


            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin.clear();
                cin.ignore();
                managerMenu();
                break;
        }

    }
}

void UserInterface::managerRegistration() {
    cout << "----------------------- REGISTRATION FORM -----------------------" << endl;
    string username;
    string password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    if (userController->findManager(username))
        throw invalid_argument("Username is taken");
    userController->addManager(username, password);
    cout << "Welcome " << username << endl;
    userController->updateManagerDataBase();
}

void UserInterface::managerLogIn() {
    cout << "----------------------- LOGIN -----------------------" << endl;
    string username;
    string password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    if (!userController->checkManagerAccount(username, password))
        throw invalid_argument("");
    cout << "Welcome back " << username << endl;
}

void UserInterface::clientMenu() {
    bool running = true;
    string option;
    while (running) {
        int choice;
        cout << "----------------------- WELCOME TO ELECTRONIC~CARS.COM -----------------------" << endl;
        cout << "1. Register" << endl;
        cout << "2. Log in" << endl;
        cout << "3. Back" << endl;
        cout << "Enter your choice and press enter: " << endl;
        cout << ">";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << endl;

                try {
                    clientRegistration();
                }
                catch (exception &e) {
                    cout << "Username is already taken" << endl;
                    clientRegistration();
                }
                cout << endl;
                cout << "Would you like to log out? (yes / no)\n";
                cout << ">";
                cin >> option;
                if (option == "yes")
                    running = false;
                if (option == "no") {
                    option.clear();
                    clientUI();
                }

                break;
            case 2:
                cout << endl;
                try {
                    clientLogIn();
                }
                catch (exception &e) {
                    cout << "Something went wrong" << endl;
                    cout << "Incorrect username or password" << endl;
                    clientLogIn();
                }
                cout << endl;
                cout << "Would you like to log out? (yes / no)\n";
                cout << ">";
                cin >> option;
                if (option == "yes")
                    running = false;
                if (option == "no") {
                    option.clear();
                    clientUI();
                }
                break;
            case 3:
                running = false;
                mainMenu();
                break;

            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                clientMenu();
                cin.clear();
                cin.ignore();
                break;
        }
    }
}

void UserInterface::clientLogIn() {
    cout << "----------------------- LOGIN -----------------------" << endl;
    string username;
    string password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (!userController->checkClientAccount(username, password))
        throw invalid_argument("");

    cout << "Welcome back " << username << endl;
}

void UserInterface::clientRegistration() {
    cout << "----------------------- REGISTRATION FORM -----------------------" << endl;
    string username;
    string password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    if (userController->findClient(username))
        throw invalid_argument("Username is taken");
    userController->addClient(username, password);
    cout << "Welcome " << username << endl;
    userController->updateClientDataBase();
}

void UserInterface::showAll() {
    vector<ElectricScooter> scooters = scooterController->getAll();
    cout << "----------------------- ELECTRIC ~ SCOOTERS -----------------------" << endl;
    cout << endl;
    for (auto &scooter: scooters) {
        cout << "Model: " << scooter.getModel() << endl;
        cout << "    o Identifier: " << scooter.getId() << endl;
        cout << "    o Date of commissioning: " << scooter.getDateAsString() << endl;
        cout << "    o Mileage: " << scooter.getMileage() << endl;
        cout << "    o Last Location: " << scooter.getLocation() << endl;
        cout << "    o Current Condition: " << scooter.getCondition() << endl;
        cout << endl;
    }
}

void UserInterface::updateInfo() {

    cout << "----------------------- UPDATING INFORMATION -----------------------" << endl;
    cout << "Choose the corresponding identifier for the scooter(3 letters)" << endl;
    string id;
    cin >> id;
    cout << "Choose the attribute that needs to be updated" << endl;
    cout << "1. Identifier" << endl;
    cout << "2. Model" << endl;
    cout << "3. Date of commissioning" << endl;
    cout << "4. Mileage" << endl;
    cout << "5. Last Location" << endl;
    cout << "6. Current Condition" << endl;
    cout << "Enter your choice and press enter: " << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << endl;
            updateId(id);
            cout << endl;
            break;
        case 2:
            cout << endl;
            updateModel(id);
            cout << endl;
            break;
        case 3:
            cout << endl;
            updateDate(id);
            cout << endl;
            break;
        case 4:
            cout << endl;
            updateMileage(id);
            cout << endl;
            break;
        case 5:
            cout << endl;
            updateLocation(id);
            cout << endl;
            break;
        case 6:
            cout << endl;
            updateCondition(id);
            cout << endl;

        default:
            cout << "Not a Valid Choice. \n";
            cout << "Choose again.\n";
            cin >> choice;
            break;
    }
}

void UserInterface::updateId(const string &id) {
    string newValue;
    cout << "Enter new value: " << endl;
    cin >> newValue;
    try { scooterController->updateID(newValue, id); }
    catch (exception &e) {
        cout << "Scooter is not on the list" << endl;
        updateInfo();
    }
    cout << "Update completed.." << endl;
}

void UserInterface::updateModel(const string &id) {
    string newValue;
    cout << "Enter new value: " << endl;
    cin >> newValue;
    try { scooterController->updateModel(newValue, id); }
    catch (exception &e) {
        cout << "Scooter is not on the list" << endl;
        updateInfo();
    }
    cout << "Update completed.." << endl;

}

void UserInterface::updateDate(const string &id) {
    string newValue;
    cout << "Enter new value: " << endl;
    cin >> newValue;
    try { scooterController->updateDate(newValue, id); }
    catch (exception &e) {
        cout << "Scooter is not on the list" << endl;
        updateInfo();
    }
    cout << "Update completed.." << endl;

}

void UserInterface::updateMileage(const string &id) {
    float newValue;
    cout << "Enter new value: " << endl;
    cin >> newValue;
    try { scooterController->updateMileage(newValue, id); }
    catch (exception &e) {
        cout << "Scooter is not on the list" << endl;
        updateInfo();
    }
    cout << "Update completed.." << endl;

}

void UserInterface::updateLocation(const string &id) {
    string newValue;
    cout << "Enter new value: " << endl;
    cin >> newValue;
    try { scooterController->updateLocation(newValue, id); }
    catch (exception &e) {
        cout << "Scooter is not on the list" << endl;
        updateInfo();
    }
    cout << "Update completed.." << endl;

}

void UserInterface::updateCondition(const string &id) {
    string newValue;
    cout << "Enter new value: " << endl;
    cin >> newValue;
    try { scooterController->updateCondition(newValue, id); }
    catch (exception &e) {
        cout << "Scooter is not on the list" << endl;
        updateInfo();
    }
    cout << "Update completed.." << endl;

}

void UserInterface::managerUI() {
    int userInput = -1;
    while(userInput != 0) {
        cout << "----------------------- MANAGER UI -----------------------";
        cout << "\n\nChoose one of the followings\n\n";
        cout << "0. Back\n";
        cout << "1. Add scooter\n";
        cout << "2. Remove scooter\n";
        cout << "3. Update scooter\n";
        cout << "4. Find scooters by location\n";
        cout << "5. Find scooters by commissioning date\n";
        cout << "6. Find scooters by mileage\n";
        cout << "7. Show all scooters sorted by age\n";
        cout << "8. See all scooters\n\n";

        cout << ">";
        cin >> userInput;
        cout << endl;

        switch (userInput) {
            case 0: {
                break;
            }
            case 1: {
                string id, model, date, location, condition;
                float mileage;

                cout << "ID: ";
                cin >> id;
                cout << "Model: ";
                cin >> model;
                cout << "Commission Date(Y-M-D): ";
                cin >> date;
                cout << "Mileage(km): ";
                cin >> mileage;
                cout << "Location: ";
                cin >> location;
                cout << "Condition: ";
                cin >> condition;

                try {
                    scooterController->add(id, model, date, mileage, location, condition);
                    scooterController->update();
                    cout << "\nScooter successfully added\n\n";
                } catch (exception &e) {
                    cout << "\nOne or more attributes are not valid\n";
                }
                break;
            }
            case 2: {
                string id;
                cout << "Write the ID of the scooter that you want to remove: ";
                cin >> id;

                try {
                    scooterController->remove(id);
                    scooterController->update();
                    cout << "\nScooter successfully removed\n\n";
                } catch (exception &e) {
                    cout << "\nThe given ID is not valid";
                }
                break;
            }
            case 3: {
                updateInfo();
                scooterController->update();
                break;
            }
            case 4: {
                string location;
                cout << "Scooter's location: ";
                cin >> location;

                try {
                    scooterController->lastLocationSearch(location);
                } catch (exception &e) {
                    cout << "\nThe given location is not valid\n";
                }

                vector<ElectricScooter> scooters = scooterController->lastLocationSearch(location);
                for(auto it : scooters)
                    cout << it.toString() << '\n';
                break;
            }
            case 5: {
                Date date;
                int day, month, year;

                cout << "Scooter's commissioning date\n";
                cout << "Year: ";
                cin >> year;
                date.setYear(year);
                cout << "Month: ";
                cin >> month;
                date.setMonth(month);
                cout << "Day: ";
                cin >> day;
                date.setDay(day);

                try {
                    scooterController->ageFiltered(date);
                } catch (exception &e) {
                    cout << "\nThe given date is not valid\n";
                }

                vector<ElectricScooter> scooters = scooterController->ageFiltered(date);
                for(auto it : scooters)
                    cout << it.toString() << '\n';
                break;
            }
            case 6: {
                float mileage;
                cout << "Mileage value: ";
                cin >> mileage;

                try {
                    scooterController->mileageFiltered(mileage);
                } catch (exception &e) {
                    cout << "\nThe given mileage is not valid\n";
                }

                vector<ElectricScooter> scooters = scooterController->mileageFiltered(mileage);
                for(auto it : scooters)
                    cout << it.toString() << '\n';
                break;
            }
            case 7: {
                vector<ElectricScooter> scooters = scooterController->ageSorted();
                for(auto it : scooters)
                    cout << it.toString() << '\n';
                break;
            }
            case 8: {
                showAll();
                break;
            }

            default: {
                cout << "Invalid choice...\n";
                cout << "Try again\n";
                managerUI();
                break;
            }
        }
    }
}

void UserInterface::clientUI() {
    int userInput = -1;
    while(userInput != 0) {
        cout << "----------------------- Client UI -----------------------";
        cout << "\n\nChoose one of the followings\n\n";
        cout << "0. Back\n";
        cout << "1. Find scooters by location\n";
        cout << "2. Find scooters by commissioning date\n";
        cout << "3. Find scooters by mileage\n";
        cout << "4. Reserve a scooter\n";
        cout << "5. Use a scooters\n";
        cout << "6. See all scooters\n\n";

        cout << ">";
        cin >> userInput;
        cout << endl;

        switch (userInput) {
            case 0: {
                break;
            }
            case 1: {
                string location;
                cout << "Scooter's location: ";
                cin >> location;

                try {
                    scooterController->lastLocationSearch(location);
                } catch (exception &e) {
                    cout << "\nThe given location is not valid\n";
                }

                vector<ElectricScooter> scooters = scooterController->lastLocationSearch(location);
                for(auto it : scooters)
                    cout << it.toString() << '\n';
                break;
            }
            case 2: {
                Date date;
                int day, month, year;

                cout << "Scooter's commissioning date\n";
                cout << "Year: ";
                cin >> year;
                date.setYear(year);
                cout << "Month: ";
                cin >> month;
                date.setMonth(month);
                cout << "Day: ";
                cin >> day;
                date.setDay(day);

                try {
                    scooterController->ageFiltered(date);
                } catch (exception &e) {
                    cout << "\nThe given date is not valid\n";
                }

                vector<ElectricScooter> scooters = scooterController->ageFiltered(date);
                for(auto it : scooters)
                    cout << it.toString() << '\n';
                break;
            }
            case 3: {
                float mileage;
                cout << "Mileage value: ";
                cin >> mileage;

                try {
                    scooterController->mileageFiltered(mileage);
                } catch (exception &e) {
                    cout << "\nThe given mileage is not valid\n";
                }

                vector<ElectricScooter> scooters = scooterController->mileageFiltered(mileage);
                for(auto it : scooters)
                    cout << it.toString() << '\n';
                break;
            }
            case 4: {
                string id;
                showAll();

                cout << "Write de id of the scooter that you want to reserve:\n";
                cout << ">";
                cin >> id;

                try {
                    scooterController->reserveScooter(id);
                    scooterController->update();
                    cout << "The selected scooter was reserved\n\n";
                } catch (exception &e) {
                    cout << "\nThe selected scooter is not available\n";
                }
                break;
            }
            case 5: {
                string id;
                showAll();

                cout << "Write de id of the scooter that you want to reserve:\n";
                cout << ">";
                cin >> id;

                try {
                    scooterController->useScooter(id);
                    scooterController->update();
                } catch (exception &e) {
                    cout << "\nThe selected scooter is not available\n";
                }
                break;
            }
            case 6: {
                showAll();
                break;
            }

            default: {
                cout << "Invalid choice...\n";
                cout << "Try again\n";
                clientUI();
                break;
            }
        }
    }
}