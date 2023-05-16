#pragma once

#include "../AbstractRepository.h"
#include <memory>
#include <vector>
#include "../../Domain/Domain.h"

using std::vector, std::shared_ptr, std::unique_ptr;
using Domain::User;

namespace Repository {
    ///Template repository for all types of users
    class UserRepository : public AbstractRepository {
    protected:
        shared_ptr<vector<User>> data;

    public:
        ///Constructor
        explicit UserRepository(const string &_fileName);

        ///Add to Data Base
        void add(const User &user);

        ///Remove from Data Base
        void remove(const User &user);

        ///Update the Data Base
        void update() override;

        ///Delete the Data Base
        void deleteAllData();

        ///Get All data from the Data Base
        virtual vector<User> getAll();

        ///Get a pointer to the Data Base
        shared_ptr<vector<User>> getAllAsPointer();
    };
}