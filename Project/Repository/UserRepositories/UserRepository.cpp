#include "UserRepository.h"
#include <fstream>
#include <sstream>

/**
 * User repository constructor
 * @details Open the file where the data is located and convert the contents of the file into usable data
 * @throws invalid_argument if the file is not found
 */
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

///Add a new user to the Data Base
///@throws invalid_argument if the username is taken
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

///Remove a user from the Data Base
///@throws invalid_argument if the user is not found
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

///Update the Data Base with the new information
///@details This function is intended to be used only when exiting the programme
///@warning Please use this function when the programme finishes
void Repository::UserRepository::update() {
    ofstream file(fileName);
    for (auto &it: *data) {
        file << it.getUsername() << ',';
        file << it.getPassword() << '\n';
    }
}

///Get all the data in the Data Base
vector<User> Repository::UserRepository::getAll() {
    if (data->empty())
        return {};
    return *data;
}

///Get a pointer to all the data in the Data Base
shared_ptr<vector<User>> Repository::UserRepository::getAllAsPointer() {
    return std::make_shared<vector<User>>(*data);
}

///Delete everything from the Data Base
void Repository::UserRepository::deleteAllData() {
    data = make_shared<vector<User>>();
}