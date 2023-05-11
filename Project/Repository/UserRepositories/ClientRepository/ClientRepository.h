#include "../../../Domain/User/Client/Client.h"
#include <vector>
#include "../UserRepository.h"

using namespace Domain;
using namespace std;

namespace Repository {
    class ClientRepository : public UserRepository{
    public:
        explicit ClientRepository(const string &_fileName = "Repository/Data/ClientDatabase");

        void add(const Client& client);

        void remove(const Client& client);
    };
}