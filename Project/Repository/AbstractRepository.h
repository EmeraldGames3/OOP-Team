#pragma once

#include <string>

using std::string;

namespace Repository {
    ///Template repository
    class AbstractRepository {
    protected:
        string fileName;
    public:
        virtual void update() = 0;
    };
}