//#include "../../Repository/UserRepositories/ClientRepository/ClientRepository.h"
//#include "../../Repository/UserRepositories/ManagerRepository/ManagerRepository.h"
//#include <memory>
//
//using namespace Repository;
//
//namespace Controller {
//    class UserController {
//    public:
//        shared_ptr<ClientRepository> clientRepository;
//        shared_ptr<ManagerRepository> managerRepository;
//    public:
//        explicit UserController(
//                shared_ptr<ClientRepository> clientRepo = std::make_shared<ClientRepository>(ClientRepository()),
//                shared_ptr<ManagerRepository> managerRepo = std::make_shared<ManagerRepository>(ManagerRepository())
//        );
//
//        void addClient(const string &username, const string &password);
//
//        void removeClient(const string &username, const string &password);
//
//        bool checkClientAccount(const string &username, const string &password);
//
//        bool findClient(const string &username);
//
//        void updateClientDataBase();
//
//        void deleteClientData();
//
//        void addManager(const string &username, const string &password);
//
//        void removeManager(const string &username, const string &password);
//
//        bool checkManagerAccount(const string &username, const string &password);
//
//        bool findManager(const string &username);
//
//        void updateManagerDataBase();
//
//        void deleteManagerData();
//
//        void updateDataBases();
//    };
//}
