#pragma once

#include "Date/Date.h"
#include "User/Client/Client.h"
#include "User/Manager/Manager.h"
#include "User/User/User.h"
#include "ElectricScooter/ElectricScooter.h"

namespace Domain {
    class Date;
    class User;
    class Manager;
    class User;
    class ElectricScooter;
    class ObjectWithId;

    template<typename T> concept IsSubclassOfObjectWithID = std::is_base_of<ObjectWithId, T>::value;
}