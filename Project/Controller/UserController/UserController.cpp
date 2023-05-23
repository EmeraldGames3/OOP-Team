#include "UserController.h"
#include <utility>

using namespace Controller;

UserController::UserController(shared_ptr<CrudRepository<User>> clientRepo,
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
    if(clientRepository->remove(Client(password, username)))
        return true;
    return false;
}

bool UserController::removeManager(const string &username, const string &password) {
    if(managerRepository->remove(Manager(username, password)))
        return true;
    return false;
}

bool UserController::checkClientAccount(const string &username, const string &password) {
    for (auto &client: clientRepository->findAll())
        if (client.getUsername() == username && client.getPassword() == password)
            return true;
    return false;
}

bool UserController::checkManagerAccount(const string &username, const string &password) {
    for (auto &manager: managerRepository->findAll())
        if (manager.getUsername() == username && manager.getPassword() == password)
            return true;
    return false;
}

bool UserController::findClient(const string &username) {
    for (auto &client: clientRepository->findAll())
        if (client.getUsername() == username)
            return true;
    return false;
}

bool UserController::findManager(const string &username) {
    for (auto &manager: managerRepository->findAll())
        if (manager.getUsername() == username)
            return true;
    return false;
}

bool UserController::updateClient(const Client &oldClient, const Client &updatedClient) {
    if(clientRepository->update(oldClient, updatedClient))
        return true;
    return false;
}

bool UserController::updateManager(const Manager &oldClient, const Manager &updatedClient) {
    if(managerRepository->update(oldClient, updatedClient))
        return true;
    return false;
}

bool UserController::reserveScooter(Client client, const shared_ptr<ElectricScooter> &electricScooter) {
    if(electricScooter->isReserved())
        return false;

    client.reserveScooter(electricScooter);
    electricScooter->reserve();

    if(clientRepository->update(client, client))
        return true;

    return false;
}

bool UserController::freeScooter(Client client, const shared_ptr<ElectricScooter> &electricScooter) {
    if(!electricScooter->isReserved())
        return false;

    client.freeScooter(electricScooter);
    electricScooter->free();

    if(clientRepository->update(client, client))
        return true;

    return false;
}