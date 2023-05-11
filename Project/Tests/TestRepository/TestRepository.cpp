#include "TestRepository.h"
#include "../../Repository/Repository.h"
#include <cassert>

using namespace Repository;

void testRepository(){
    {
        try{
            UserRepository userRepository("false");
            assert(false);
        }catch(const exception &e){
            assert(true);
        }
    }

    {
        auto userRepository = UserRepository("Tests/TestRepository/TestDataBase/EmptyFile");
        assert(userRepository.getAllAsPointer()->empty());
        userRepository.add(User("a", "a"));
        userRepository.add(User("b", "a"));
        userRepository.add(User("c", "a"));

        auto values = userRepository.getAllAsPointer();
        for(const auto &it: *values){
            assert(it.getPassword() == "a");
        }

        assert(values->at(0).getUsername() == "a");
        assert(values->at(1).getUsername() == "b");
        assert(values->at(2).getUsername() == "c");

        userRepository.remove(User("a", "a"));
        userRepository.remove(User("b", "a"));
        userRepository.remove(User("c", "a"));

        assert(userRepository.getAll().empty());

        try{
            userRepository.remove(User("a", "a"));
            assert(false);
        } catch (const exception &exception){
            assert(true);
        }
    }

    {
        auto userRepository = UserRepository("Tests/TestRepository/TestDataBase/TestUserDataBase");
        auto values = userRepository.getAllAsPointer();
        assert(!values->empty());

        assert(values->at(0).getUsername() == "antonia_kocsis");
        assert(values->at(0).getPassword() == "29466");

        assert(values->at(1).getUsername() == "Bogdan");
        assert(values->at(1).getPassword() == "1234");
    }
}