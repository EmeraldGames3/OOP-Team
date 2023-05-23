#include "TestUserController.h"
#include <cassert>
#include "../../../Controller/Controller.h"

using namespace Controller;

void testUserController() {
    auto clients = vector<Client>();
    for (int i = 0; i < 10; i++) {
        clients.emplace_back(to_string(i), to_string(i));
    }

    auto managers = vector<Manager>();
    for (int i = 0; i < 10; i++) {
        managers.emplace_back("Mergiu" + to_string(i), to_string(i));
    }

    InMemoryRepository<Client> repository1(clients);
    InMemoryRepository<Manager> repository2(managers);

    UserController userController(make_shared<InMemoryRepository<Client>>(repository1),
                                  make_shared<InMemoryRepository<Manager>>(repository2));

    for (int i = 0; i < 10; i++) {
        assert(userController.checkClientAccount(to_string(i), to_string(i)));
        assert(userController.findClient(to_string(i)));
        assert(userController.checkManagerAccount("Mergiu" + to_string(i), to_string(i)));
        assert(userController.findManager("Mergiu" + to_string(i)));

        assert(!userController.checkClientAccount("111", "111"));
        assert(!userController.findClient("111"));
        assert(!userController.checkManagerAccount("c", "c"));
        assert(!userController.findManager("c"));
    }

    assert(userController.removeClient("1", "1"));
    assert(!userController.findClient("1"));

    assert(userController.removeManager("Mergiu0", "1"));
    assert(!userController.findManager("Mergiu0"));

    userController.addClient("11", "11");
    userController.addManager("Mergiu01", "11");

    assert(userController.findClient("11"));
    assert(userController.findManager("Mergiu01"));

    assert(userController.updateClient(Client("11", "11"),
                                       Client("1", "1")));
    assert(userController.updateManager(Manager("Mergiu01", "11"),
                                        Manager("Mergiu0", "0")));

    for (int i = 0; i < 10; i++) {
        assert(userController.checkClientAccount(to_string(i), to_string(i)));
        assert(userController.findClient(to_string(i)));
        assert(userController.checkManagerAccount("Mergiu" + to_string(i), to_string(i)));
        assert(userController.findManager("Mergiu" + to_string(i)));

        assert(!userController.checkClientAccount("111", "111"));
        assert(!userController.findClient("111"));
        assert(!userController.checkManagerAccount("c", "c"));
        assert(!userController.findManager("c"));
    }
}