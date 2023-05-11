#include "UserRepository.h"
#include <fstream>
#include <sstream>

Repository::UserRepository::UserRepository(const string &_fileName) {
    fileName = _fileName;
    ifstream file(fileName);
    data = std::make_shared<vector<User>>();

    if (!file)
        throw std::invalid_argument("File not found");

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
        data->push_back(admin);
        words.clear(); // clear the vector for the next line
    }
}

void Repository::UserRepository::add(const User &user) {
    bool found = false;
    for (auto &it: *data)
        if (it.getUsername() == user.getUsername()) {
            found = true;
            break;
        }
    if (found)
        throw invalid_argument("Username is taken");
    data->push_back(user);
}

void Repository::UserRepository::remove(const User &user) {
    bool found = false;
    for (int i = 0; i < data->size(); i++)
        if (data->at(i).getUsername() == user.getUsername()) {
            data->erase(data->begin() + i);
            found = true;
            break;
        }
    if (!found)
        throw invalid_argument("No Domain found");
}

void Repository::UserRepository::update() {
    ofstream file(fileName);
    for (auto &it: *data) {
        file << it.getUsername() << ',';
        file << it.getPassword() << '\n';
    }
}

vector<User> Repository::UserRepository::getAll() {
    if(data->empty())
        return {};
    return *data;
}

shared_ptr<vector<User>> Repository::UserRepository::getAllAsPointer() {
    return std::make_shared<vector<User>>(*data);
}
