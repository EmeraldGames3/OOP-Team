#pragma once

#include "../../../Domain/User/Client/Client.h"
#include <vector>
#include "../UserRepository.h"

using namespace Domain;
using namespace std;

namespace Repository {
    ///Repository to control all client data
    class ClientRepository : public UserRepository {
    public:
        ///Constructor with default arguments
        explicit ClientRepository(const string &_fileName = "Repository/Data/ClientDatabase");

        ///Overloaded add function
        void add(const Client &client);

        ///Overloaded remove function
        void remove(const Client &client);
    };
}