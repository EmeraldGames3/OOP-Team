#include "ManagerRepository.h"
#include <fstream>
#include <sstream>

using namespace Repository;

ManagerRepository::ManagerRepository(const string &_fileName) : UserRepository(_fileName){}

void ManagerRepository::add(const Manager &manager) {
    UserRepository::add(manager);
}

void ManagerRepository::remove(const Manager &manager) {
    UserRepository::remove(manager);
}