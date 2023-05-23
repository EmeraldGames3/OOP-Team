#pragma once

#include <string>
#include <memory>

using std::string, std::unique_ptr, std::shared_ptr;

namespace Domain {
    class ObjectWithId {
    protected:
        string identifier;

    public:
        virtual ~ObjectWithId() = default;

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

        ///Convert the Object to a string
        virtual string toString() = 0;

        ///Convert a string into an object
        virtual shared_ptr<ObjectWithId> convertFromString(const string &objectAsString) = 0;

        ///Get a vector with all the attributes of the object as a string
        virtual string getAttributes() = 0;
    };
}