#include "../User/User.h"

using namespace Domain;
namespace Domain {
    class Manager : public User {
    public:
        Manager(const string &username, const string &password);
    };
}