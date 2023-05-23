#include "TestCSVFileRepository.h"
#include "../../../Repository/Repository.h"
#include <cassert>
#include <exception>

using namespace Repository;

void testCSVFileRepository() {
    try {
        CSVFileRepository<User> repository("T");
        assert(false);
    } catch (const std::invalid_argument &exception) {
        assert(true);
    }

    {
        CSVFileRepository<User> repository("Tests/TestRepository/TestDataBase/EmptyFile");
    }

    CSVFileRepository<User> repository("Tests/TestRepository/TestDataBase/TestUserDataBase");
    assert(repository.findAll()[0].getUsername() == "antonia_kocsis");
    assert(repository.findAll()[0].getPassword() == "29466");
    assert(repository.findAll()[1].getUsername() == "Bogdan");
    assert(repository.findAll()[1].getPassword() == "1234");

    repository.create(User("Mergiu", "Sedrea"));
    assert(repository.findAll()[2].getUsername() == "Mergiu");
    assert(repository.findAll()[2].getPassword() == "Sedrea");

    assert(repository.update(
            User("Mergiu", "Sedrea"), User("Dinosour", "1")));

    assert(repository.findAll()[2].getUsername() == "Dinosour");
    assert(repository.findAll()[2].getPassword() == "1");

    assert(repository.remove(User("Dinosour", "1")));
}