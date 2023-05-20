#pragma once

#include <string>

using std::string;

namespace Domain {
    class ObjectWithId {
    protected:
        string identifier;

    public:
        ///ID setter
        ///@throws invalid_argument if the identifier has an invalid format
        virtual void setId(const string &newID) {
            if (newID.size() != 3)
                throw std::invalid_argument("Invalid ID");
            identifier = newID;
        }

        ///Id getter
        [[nodiscard]] string getId() const {
            return identifier;
        }

        ///Overloaded virtual operator ==
        virtual bool operator==(const ObjectWithId &other){
            return this->identifier == other.identifier;
        }

        ///Overloaded virtual operator !=
        virtual bool operator!=(const ObjectWithId &other){
            return !(*this == other);
        }
    };
}

