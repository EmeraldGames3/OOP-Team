#include "ManagerRepository.h"
#include <fstream>
#include <sstream>

using namespace Repository;

///Create a new UserRepository
///@details This function is intended to be used with its default arguments
ManagerRepository::ManagerRepository(const string &_fileName) : UserRepository(_fileName) {}

///Overloaded add function
void ManagerRepository::add(const Manager &manager) {
    UserRepository::add(manager);
}

///Overloaded remove function
void ManagerRepository::remove(const Manager &manager) {
    UserRepository::remove(manager);
}