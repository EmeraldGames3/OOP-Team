#pragma once

#include <string>

using std::string;

namespace Repository{
    class AbstractRepository{
    protected:
        string fileName;
    public:
        virtual void add() = 0;

        virtual void remove() = 0;

        virtual void update() = 0;

        virtual void writeToFile() = 0;
    };
}