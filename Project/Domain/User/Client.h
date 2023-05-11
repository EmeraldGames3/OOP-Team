#include "User.h"

using namespace user;

namespace Domain {
    class Client : public User {
    public:
        Client(const string &username, const string &password);

    };
}