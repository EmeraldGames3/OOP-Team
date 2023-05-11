#pragma once

#include "../AbstractRepository.h"
#include <memory>
#include <vector>
#include "../../Domain/Domain.h"

using std::vector, std::shared_ptr, std::unique_ptr;
using Domain::User;

namespace Repository {
    class UserRepository : public AbstractRepository{
    protected:
        shared_ptr<vector<User>> data;

    public:
        explicit UserRepository(const string &_fileName);

        void add(const User &user);

        void remove(const User &user);

        void update() override;

        virtual vector<User> getAll();

        shared_ptr<vector<User>> getAllAsPointer();
    };
}