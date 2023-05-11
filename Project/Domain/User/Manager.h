#include "User.h"

using namespace user;
namespace Domain {
    class Manager : public User {
    public:
        Manager(const string &username, const string &password);

    };
}