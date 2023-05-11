#include "ClientRepository.h"
#include <fstream>
#include <sstream>

using namespace Repository;

ClientRepository::ClientRepository() {
    ifstream file;
    file.open("ClientDatabase");
    if (file.peek() == std::ifstream::traits_type::eof())
        this->clientRepo = {};
    else {
        string line;
        string username;
        string password;
        std::vector<std::string> words;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string word;
            while (std::getline(ss, word, ',')) {
                words.push_back(word);
            }
            username = words[0];
            password = words[1];
            Client admin(username, password);
            clientRepo.push_back(admin);
            words.clear(); // clear the vector for the next line
        }

    }
}

void ClientRepository::updateDatabase() {
    ofstream file;
    file.open("ClientDatabase");
    for (int i = 0; i < clientRepo.size(); i++) {
        file << clientRepo[i].getUsername() << ',';
        file << clientRepo[i].getPassword() << endl;
    }
}

void ClientRepository::add(Client client) {
    bool found = false;
    for (int i = 0; i < clientRepo.size(); i++)
        if (clientRepo[i].getUsername() == client.getUsername()) {
            found = true;
            break;
        }
    if (found)
        throw invalid_argument("Username is taken");
    clientRepo.push_back(client);
    updateDatabase();
}

void ClientRepository::remove(Client client) {
    bool found = false;
    for (int i = 0; i < clientRepo.size(); i++)
        if (clientRepo[i].getUsername() == client.getUsername()) {
            clientRepo.erase(clientRepo.begin() + i);
            found = true;
            break;
        }
    if (!found)
        throw invalid_argument("No Domain found");
    updateDatabase();
}

vector<Client> ClientRepository::getAll() {
    return clientRepo;
}