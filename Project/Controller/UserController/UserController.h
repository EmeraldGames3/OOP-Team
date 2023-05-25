#pragma once

#include "../../Repository/Repository.h"
#include "../../Domain/Domain.h"
#include <memory>

using namespace Repository;

namespace Controller {
    class UserController {
    private:
        shared_ptr<CrudRepository<Client>> clientRepository;
        shared_ptr<CrudRepository<Manager>> managerRepository;
        shared_ptr<vector<ElectricScooter>> currentClientsReservedScooters;

        friend class ElectricScooterController;

    public:
        explicit UserController(shared_ptr<CrudRepository<Client>> clientRepo,
                                shared_ptr<CrudRepository<Manager>> managerRepo);

        void addClient(const string &username, const string &password);

        void addManager(const string &username, const string &password);

        bool removeClient(const string &username, const string &password);

        bool removeManager(const string &username, const string &password);

        bool checkClientAccount(const string &username, const string &password);

        bool checkManagerAccount(const string &username, const string &password);

        bool findClient(const string &username);

        bool findManager(const string &username);

        bool updateClient(const Client &oldClient, const Client &updatedClient);

        bool updateManager(const Manager &oldClient, const Manager &updatedClient);
    };
}