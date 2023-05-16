#include "ClientRepository.h"

using namespace Repository;

///Constructor with default parameters
///@details This function is intended to be used with its default arguments
ClientRepository::ClientRepository(const string &_fileName) : UserRepository(_fileName) {}

///Overloaded add function
void ClientRepository::add(const Client &client) {
    UserRepository::add(client);
}

///Overloaded remove function
void ClientRepository::remove(const Client &client) {
    UserRepository::remove(client);
}