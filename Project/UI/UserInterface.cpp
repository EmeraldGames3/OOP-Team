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
    cin >> choice;
    switch (choice) {
        case 1:
            managerMenu();
            break;
        case 2:
            clientMenu();
            break;
        case 3:
            break;
        default:
            break;
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
        cout << "3. Exit " << endl;
        cout << "Enter your choice and press enter: " << endl;
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
                cout << "Would you like to log out? (yes / no)";
                cin >> option;
                if (option == "yes")
                    running = false;
                if (option == "no")
                    option.clear();

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
                cout << "Would you like to log out? (yes / no)";
                cin >> option;
                if (option == "yes")
                    running = false;
                if (option == "no")
                    option.clear();
                break;
            case 3:
                running = false;
                break;


            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }

    }
}

void UserInterface::managerRegistration() {
    cout << "----------------------- REGISTRATION FORM -----------------------" << endl;
    string username;
    string password;
    cout << "Username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
    cin >> password;
    if (userController->findManager(username))
        throw invalid_argument("Username is taken");
    userController->addManager(username, password);
    cout << "Welcome " << username << endl;
}

void UserInterface::managerLogIn() {
    cout << "----------------------- LOGIN -----------------------" << endl;
    string username;
    string password;
    cout << "Username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
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
        cout << "3. Exit " << endl;
        cout << "Enter your choice and press enter: " << endl;
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
                cout << "Would you like to log out? (yes / no)";
                cin >> option;
                if (option == "yes")
                    running = false;
                if (option == "no")
                    option.clear();

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
                cout << "Would you like to log out? (yes / no)";
                cin >> option;
                if (option == "yes")
                    running = false;
                if (option == "no")
                    option.clear();
                break;
            case 3:
                running = false;
                break;


            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }

    }
}

void UserInterface::clientLogIn() {
    cout << "----------------------- LOGIN -----------------------" << endl;
    string username;
    string password;
    cout << "Username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
    cin >> password;
    if (userController->checkClientAccount(username, password))
        throw invalid_argument("");
    cout << "Welcome back " << username << endl;
    //movieMenu();
}

void UserInterface::clientRegistration() {
    cout << "----------------------- REGISTRATION FORM -----------------------" << endl;
    string username;
    string password;
    cout << "Username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
    cin >> password;
    if (userController->findClient(username))
        throw invalid_argument("Username is taken");
    userController->addClient(username, password);
    cout << "Welcome " << username << endl;
    //movieMenu();
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



