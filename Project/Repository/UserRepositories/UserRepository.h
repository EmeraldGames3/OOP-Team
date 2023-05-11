#pragma once

#include "../AbstractRepository.h"
#include <memory>
#include <vector>
#include "../../Domain/Domain.h"

using std::vector, std::shared_ptr, std::unique_ptr;
using Domain::User;

namespace Repository{
    class UserRepository : public AbstractRepository{
    protected:
        shared_ptr<vector<User>> data;

    public:
        UserRepository(const string &fileName);

        void add() override;

        void remove() override;

        void update() override;

        void writeToFile() override;
    };
}