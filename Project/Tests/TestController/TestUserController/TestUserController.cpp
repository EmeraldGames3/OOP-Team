#include "TestUserController.h"

// Test addClient() function
void testAddClientController() {
    // Create a new UserController with a mock clientRepository
    shared_ptr<ClientRepository> clientRepo = make_shared<ClientRepository>();
    UserController userController(clientRepo);

    // Add a client
    userController.addClient("john_doe", "password123");

    // Check if the client was added successfully
    assert(userController.findClient("john_doe"));
}

// Test removeClient() function
void testRemoveClientController() {
    // Create a new UserController with a mock clientRepository
    shared_ptr<ClientRepository> clientRepo = make_shared<ClientRepository>();
    UserController userController(clientRepo);

    // Add a client
    userController.addClient("john_doe", "password123");

    // Remove the client
    userController.removeClient("john_doe", "password123");

    // Check if the client was removed successfully
    assert(!userController.findClient("john_doe"));
}

// Test checkClientAccount() function
void testCheckClientAccountController() {
    // Create a new UserController with a mock clientRepository
    shared_ptr<ClientRepository> clientRepo = make_shared<ClientRepository>();
    UserController userController(clientRepo);

    // Add a client
    userController.addClient("john_doe", "password123");

    // Check if the client's account exists
    assert(userController.checkClientAccount("john_doe", "password123"));
    assert(!userController.checkClientAccount("john_doe", "wrong_password"));
    assert(!userController.checkClientAccount("unknown_user", "password123"));
}

// Test findClient() function
void testFindClientController() {
    // Create a new UserController with a mock clientRepository
    shared_ptr<ClientRepository> clientRepo = make_shared<ClientRepository>();
    UserController userController(clientRepo);

    // Add a client
    userController.addClient("john_doe", "password123");

    // Check if the client is found
    assert(userController.findClient("john_doe"));
    assert(!userController.findClient("unknown_user"));
}

// Test addManager() function
void testAddManager() {
    // Create a new UserController with a mock managerRepository
    shared_ptr<ManagerRepository> managerRepo = make_shared<ManagerRepository>();
    UserController userController(nullptr, managerRepo);

    // Add a manager
    userController.addManager("jane_smith", "pass123");

    // Check if the manager was added successfully
    assert(userController.findManager("jane_smith"));
}

// Test removeManager() function
void testRemoveManager() {
    // Create a new UserController with a mock managerRepository
    shared_ptr<ManagerRepository> managerRepo = make_shared<ManagerRepository>();
    UserController userController(nullptr, managerRepo);

    // Add a manager
    userController.addManager("jane_smith", "pass123");

    // Remove the manager
    userController.removeManager("jane_smith", "pass123");

    // Check if the manager was removed successfully
    assert(!userController.findManager("jane_smith"));
}

// Test checkManagerAccount() function
void testCheckManagerAccount() {
    // Create a new UserController with a mock managerRepository
    shared_ptr<ManagerRepository> managerRepo = make_shared<ManagerRepository>();
    UserController userController(nullptr, managerRepo);

    // Add a manager
    userController.addManager("jane_smith", "pass123");

    // Check if the manager's account exists
    assert(userController.checkManagerAccount("jane_smith", "pass123"));
    assert(!userController.checkManagerAccount("jane_smith", "wrong_pass"));
    assert(!userController.checkManagerAccount("unknown_user", "pass123"));
}

// Test findManager() function
void testFindManager() {
    // Create a new UserController with a mock managerRepository
    shared_ptr<ManagerRepository> managerRepo = make_shared<ManagerRepository>();
    UserController userController(nullptr, managerRepo);

    // Add a manager
    userController.addManager("jane_smith", "pass123");

    // Check if the manager is found
    assert(userController.findManager("jane_smith"));
    assert(!userController.findManager("unknown_user"));
}

void testUserController() {
    testAddClientController();
    testRemoveClientController();
    testCheckClientAccountController();
    testFindClientController();

    testAddManager();
    testRemoveManager();
    testCheckManagerAccount();
    testFindManager();
}