#include "UserController.h"
#include <utility>
#include <algorithm>

using namespace Controller;

UserController::UserController(shared_ptr<CrudRepository<Client>> clientRepo,
                               shared_ptr<CrudRepository<Manager>> managerRepo) {
    clientRepository = std::move(clientRepo);
    managerRepository = std::move(managerRepo);
}

void UserController::addClient(const string &username, const string &password) {
    clientRepository->create(Client(username, password));
}

void UserController::addManager(const string &username, const string &password) {
    managerRepository->create(Manager(username, password));
}

bool UserController::removeClient(const string &username, const string &password) {
    if (clientRepository->remove(Client(password, username)))
        return true;
    return false;
}

bool UserController::removeManager(const string &username, const string &password) {
    if (managerRepository->remove(Manager(username, password)))
        return true;
    return false;
}

bool UserController::checkClientAccount(const string &username, const string &password) {
    return std::ranges::any_of(clientRepository->findAll(), [&](const auto &client) {
        return client.getUsername() == username && client.getPassword() == password;
    });
}

bool UserController::checkManagerAccount(const string &username, const string &password) {
    return std::ranges::any_of(managerRepository->findAll(), [&](const auto &manager) {
        return manager.getUsername() == username && manager.getPassword() == password;
    });
}

bool UserController::findClient(const string &username) {
    return std::ranges::any_of(clientRepository->findAll(), [&](const auto &client) {
        return client.getUsername() == username;
    });
}


bool UserController::findManager(const string &username) {
    return std::ranges::any_of(managerRepository->findAll(), [&](const auto &manager) {
        return manager.getUsername() == username;
    });
}

bool UserController::updateClient(const Client &oldClient, const Client &updatedClient) {
    if (clientRepository->update(oldClient, updatedClient))
        return true;
    return false;
}

bool UserController::updateManager(const Manager &oldClient, const Manager &updatedClient) {
    if (managerRepository->update(oldClient, updatedClient))
        return true;
    return false;
}