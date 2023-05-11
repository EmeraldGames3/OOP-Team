#include "../../Repository/ClientRepository.h"
#include "../../Repository/ManagerRepository.h"
#include <memory>

using namespace Repository;
using namespace Repository;

namespace Controller {
    class UserController {
    private:
        shared_ptr<ClientRepository> clientRepository;
        shared_ptr<ManagerRepository> managerRepository;
    public:
        UserController(shared_ptr<ClientRepository> clientRepo, shared_ptr<ManagerRepository> managerRepo);

        void addClient(const string& username, const string& password);

        void removeClient(const string& username, const string& password);

        bool checkClientAccount(const string& username, const string& password);

        bool findClient(const string& username);

        void addManager(const string& username, const string& password);

        void removeManager(const string& username, const string& password);

        bool checkManagerAccount(const string& username, const string& password);

        bool findManager(const string& username);

    };

}
