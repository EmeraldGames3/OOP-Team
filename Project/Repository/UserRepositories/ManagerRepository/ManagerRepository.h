#pragma once

#include "../UserRepository.h"
#include "../../../Domain/User/Manager/Manager.h"
#include <vector>

using namespace Domain;
using namespace std;

namespace Repository {
    ///Repository to control all manager data
    class ManagerRepository : public UserRepository {
    public:
        ///Constructor with default parameters
        explicit ManagerRepository(const string &_filename = "Repository/Data/ManagerDatabase");

        ///Overloaded add function
        void add(const Manager &manager);

        ///Overloaded remove function
        void remove(const Manager &manager);
    };
}