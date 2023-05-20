#include "TestInMemoryRepository.h"
#include "../../../Repository/Repository.h"
#include <cassert>

using namespace Repository;

void testInMemoryRepository() {
    try {
        InMemoryRepository<User> repository((vector<User>()));
        assert(false); //Code should not reach this line
    } catch (const invalid_argument &exception) {
        assert(true); //Code delivers exception as expected
    }

    auto users = vector<User>();
    for (int i = 0; i < 10; i++) {
        users.emplace_back(to_string(i), to_string(i));
    }

    InMemoryRepository<User> repository(users);
    assert(repository.findAll().size() == 10); //Repository was created successfully

    for (int i = 0; i < 10; i += 2) {
        //Objects are removed successfully
        assert(repository.remove(User(to_string(i), to_string(i))));
        //Object does not exist anymore
        assert(!repository.remove(User(to_string(i), to_string(i))));
    }

    assert(repository.findAll().size() == 5);

    for (int i = 1; i < 10; i += 2) {
        //Objects remain in the same order
        auto currentUser = repository.findAll().at(i / 2);
        User expectedUser(to_string(i), to_string(i));

        assert(currentUser.getUsername() == expectedUser.getUsername() &&
               currentUser.getPassword() == currentUser.getPassword());
    }

    for (int i = 1; i < 10; i += 2) {
        User userToBeUpdated(to_string(i), to_string(i));
        User updatedUser(to_string((i + 1) / 2 - 1), to_string((i + 1) / 2 - 1));

        assert(repository.update(userToBeUpdated, updatedUser)); //User is updated successfully
    }

    for (int i = 1; i < 10; i += 2) {
        //Objects remain in the same order
        auto currentUser = repository.findAll().at(i / 2);
        User expectedUser(to_string((i + 1) / 2 - 1), to_string((i + 1) / 2 - 1));

        assert(currentUser.getUsername() == expectedUser.getUsername() &&
               currentUser.getPassword() == currentUser.getPassword());
    }

    for(int i = 5; i < 10; i++){
        // Add new users to the repository
        repository.create(User(to_string(i), to_string(i)));
    }

    for(int i = 0; i < 10; i++){
        //Check that the new objects were added successfully
        assert(repository.findAll().at(i) == users[i]);
    }
}