#include "Client.h"

#include <utility>

using namespace Domain;

Client::Client(string username, string password) : User(std::move(username), std::move(password)) {}
