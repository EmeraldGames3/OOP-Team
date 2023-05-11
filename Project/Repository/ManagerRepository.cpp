#include "ManagerRepository.h"
#include <fstream>
#include <sstream>

using namespace Repository;

ManagerRepository::ManagerRepository() {
    ifstream file;
    file.open("ManagerDatabase");
    if (file.peek() == std::ifstream::traits_type::eof())
        this->managerRepo = {};
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
            Manager admin(username, password);
            managerRepo.push_back(admin);
            words.clear(); // clear the vector for the next line
        }

    }
}

void ManagerRepository::updateDatabase() {
    ofstream file;
    file.open("ManagerDatabase");
    for (int i = 0; i < managerRepo.size(); i++) {
        file << managerRepo[i].getUsername() << ',';
        file << managerRepo[i].getPassword()  << endl;
    }
}

void ManagerRepository::add(Manager manager) {
    bool found = false;
    for (int i = 0; i < managerRepo.size(); i++)
        if (managerRepo[i].getUsername() == manager.getUsername()) {
            found = true;
            break;
        }
    if (found)
        throw invalid_argument("Username is taken");
    managerRepo.push_back(manager);
    updateDatabase();
}

void ManagerRepository::remove(Manager manager) {
    bool found = false;
    for (int i = 0; i < managerRepo.size(); i++)
        if (managerRepo[i].getUsername() == manager.getUsername()) {
            managerRepo.erase(managerRepo.begin() + i);
            found = true;
            break;
        }
    if (!found)
        throw invalid_argument("No Domain found");
    updateDatabase();
}

vector<Manager> ManagerRepository::getAll() {
    return managerRepo;
}