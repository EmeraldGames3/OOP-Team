#include "../Domain/User/Manager.h"
#include <vector>
#pragma once

using namespace Domain;
using namespace std;

namespace Repository {
    class ManagerRepository {
    private:
        vector<Manager> managerRepo;
    public:
        ManagerRepository();

        void updateDatabase();

        void add(Manager manager);

        void remove(Manager manager);

        vector<Manager> getAll();
    };
}