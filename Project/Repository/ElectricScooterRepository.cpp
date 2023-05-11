#include "ElectricScooterRepository.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace Repository;

ElectricScooterRepository::ElectricScooterRepository() {
    ifstream file;
    file.open("ScooterDatabase");
    if (file.peek() == std::ifstream::traits_type::eof())
        this->repository = {};
    else {
        string line;
        string id, model, date, location, condition;
        float mileage;
        std::vector<std::string> words;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string word;
            while (std::getline(ss, word, ',')) {
                words.push_back(word);
            }
            id = words[0];
            model = words[1];
            date = words[2];
            mileage = stof(words[3]);
            location = words[4];
            condition = words[5];
            ElectricScooter scooter(id, model, date, mileage, location, condition);
            repository.push_back(scooter);
            words.clear(); // clear the vector for the next line
        }

    }
}

void ElectricScooterRepository::updateDatabase() {
    ofstream file;
    file.open("ScooterDatabase");
    for (auto &i: repository) {
        file << i.getId() << ',';
        file << i.getModel() << ',';
        file << i.getDate() << ',';
        file << i.getMileage() << ',';
        file << i.getLocation() << ',';
        file << i.getCondition() << endl;
    }
}

void ElectricScooterRepository::add(ElectricScooter scooter) {
    for (auto &i: repository)
        if (i.getId() == scooter.getId()) {
            return;
        }
    repository.push_back(scooter);
    updateDatabase();
}

void ElectricScooterRepository::remove(ElectricScooter scooter) {
    bool found = false;
    for (int i = 0; i < repository.size(); i++)
        if (repository[i].getId() == scooter.getId()) {
            repository.erase(repository.begin() + i);
            found = true;
            break;
        }
    if (found)
        updateDatabase();
    else {
        throw invalid_argument("Item was not found!");
    }
}

void ElectricScooterRepository::updateDate(const string &date, const string &id) {
    for (auto &i: repository)
        if (i.getId() == id) {
            i.setDate(date);
            updateDatabase();
            return;
        }
}

void ElectricScooterRepository::updateCondition(const string &condition, const string &id) {
    for (auto &i: repository)
        if (i.getId() == id) {
            i.setCondition(condition);
            updateDatabase();
            break;
        }
}

void ElectricScooterRepository::updateID(const string &id, const string &oldId) {
    for (auto &i: repository)
        if (i.getId() == oldId) {
            i.setId(id);
            updateDatabase();
            return;
        }
}

void ElectricScooterRepository::updateLocation(const string &location, const string &id) {
    for (auto &i: repository)
        if (i.getId() == id) {
            i.setLocation(location);
            updateDatabase();
            return;
        }
}

void ElectricScooterRepository::updateMileage(float mileage, const string &id) {
    for (auto &i: repository)
        if (i.getId() == id) {
            i.setMileage(mileage);
            updateDatabase();
            return;
        }
}

void ElectricScooterRepository::updateModel(const string &model, const string &id) {
    for (auto &i: repository)
        if (i.getId() == id) {
            i.setModel(model);
            updateDatabase();
            return;
        }
}

vector<ElectricScooter> ElectricScooterRepository::getAll() {
    return repository;
}