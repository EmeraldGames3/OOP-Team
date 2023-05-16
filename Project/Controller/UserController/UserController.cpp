#include "UserController.h"

#include <utility>

using namespace Controller;

UserController::UserController(shared_ptr<ClientRepository> clientRepo, shared_ptr<ManagerRepository> managerRepo) {
    clientRepository = std::move(clientRepo);
    managerRepository = std::move(managerRepo);
}

void UserController::addClient(const string &username, const string &password) {
    Client client(username, password);
    clientRepository->add(client);
}

void UserController::addManager(const string &username, const string &password) {
    Manager manager(username, password);
    managerRepository->add(manager);
}

void UserController::removeClient(const string &username, const string &password) {
    Client client(username, password);
    clientRepository->remove(client);
}

void UserController::removeManager(const string &username, const string &password) {
    Manager manager(username, password);
    managerRepository->remove(manager);
}

bool UserController::checkClientAccount(const string &username, const string &password) {
    auto clients = clientRepository->getAll();
    for (auto &client: clients)
        if (client.getUsername() == username && client.getPassword() == password)
            return true;
    return false;
}

bool UserController::checkManagerAccount(const string &username, const string &password) {
    auto managers = managerRepository->getAll();
    for (auto &manager: managers)
        if (manager.getUsername() == username && manager.getPassword() == password)
            return true;
    return false;
}

bool UserController::findClient(const string &username) {
    auto clients = clientRepository->getAll();
    for (auto &client: clients)
        if (client.getUsername() == username)
            return true;
    return false;
}

bool UserController::findManager(const string &username) {
    auto managers = managerRepository->getAll();
    for (auto &manager: managers)
        if (manager.getUsername() == username)
            return true;
    return false;
}

void UserController::updateClientDataBase() {
    clientRepository->update();
}

void UserController::updateManagerDataBase() {
    managerRepository->update();
}

void UserController::deleteClientData() {
    clientRepository->deleteAllData();
}

void UserController::deleteManagerData() {
    managerRepository->deleteAllData();
}

void UserController::updateDataBases() {
    clientRepository->update();
    managerRepository->update();
}
