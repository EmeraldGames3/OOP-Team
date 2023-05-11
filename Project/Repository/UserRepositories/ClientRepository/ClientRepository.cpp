#include "ClientRepository.h"
#include <fstream>
#include <sstream>

using namespace Repository;

ClientRepository::ClientRepository(const string &_fileName) : UserRepository(_fileName) {}

void ClientRepository::add(const Client& client) {
    UserRepository::add(client);
}

void ClientRepository::remove(const Client& client) {
    UserRepository::remove(client);
}