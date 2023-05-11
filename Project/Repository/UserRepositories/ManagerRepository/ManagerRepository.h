#pragma once
#include "../UserRepository.h"
#include "../../../Domain/User/Manager/Manager.h"
#include <vector>

using namespace Domain;
using namespace std;

namespace Repository {
    class ManagerRepository : public UserRepository{
    public:
        explicit ManagerRepository(const string &_filename = "Repository/Data/ManagerDatabase");

        void add(const Manager &manager);

        void remove(const Manager &manager);
    };
}