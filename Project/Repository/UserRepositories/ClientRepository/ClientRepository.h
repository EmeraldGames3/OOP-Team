#include "../../../Domain/User/Client/Client.h"
#include <vector>


using namespace Domain;
using namespace std;

namespace Repository {
    class ClientRepository {
    private:
        vector<Client> clientRepo;
    public:
        ClientRepository();

        void updateDatabase();

        void add(Client client);

        void remove(Client client);

        vector<Client> getAll();
    };
}