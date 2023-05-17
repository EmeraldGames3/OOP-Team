#include "ElectricScooterRepository.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace Repository;

ElectricScooterRepository::ElectricScooterRepository(const string &_fileName) {
    fileName = _fileName;
    std::ifstream file(fileName);
    data = std::make_shared<vector<ElectricScooter>>();

    if (!file)
        throw std::invalid_argument("File not found");

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
        ElectricScooter scooter(id, model, date,
                                mileage, location, condition);
        data->push_back(scooter);
        words.clear(); // clear the vector for the next line
    }
}

void ElectricScooterRepository::update() {
    ofstream file(fileName);
    for (auto &i: *data) {
        file << i.getId() << ',';
        file << i.getModel() << ',';
        file << i.getDateAsString() << ',';
        file << i.getMileage() << ',';
        file << i.getLocation() << ',';
        file << i.getCondition() << endl;
    }
}

void ElectricScooterRepository::add(ElectricScooter scooter) {
    for (auto &i: *data)
        if (i.getId() == scooter.getId()) {
            return;
        }
    data->push_back(scooter);
}

void ElectricScooterRepository::remove(ElectricScooter scooter) {
    bool found = false;
    for (int i = 0; i < data->size(); i++)
        if (data->at(i).getId() == scooter.getId()) {
            data->erase(data->begin() + i);
            found = true;
            break;
        }
    if (!found)
        throw invalid_argument("Item was not found!");
}

void ElectricScooterRepository::updateDate(const string &date, const string &id) {
    for (auto &i: *data)
        if (i.getId() == id) {
            i.setDate(date);
            return;
        }
}

void ElectricScooterRepository::updateCondition(const string &condition, const string &id) {
    for (auto &i: *data)
        if (i.getId() == id) {
            i.setCondition(condition);
            break;
        }
}

void ElectricScooterRepository::updateID(const string &id, const string &oldId) {
    for (auto &i: *data)
        if (i.getId() == oldId) {
            i.setId(id);
            return;
        }
}

void ElectricScooterRepository::updateLocation(const string &location, const string &id) {
    for (auto &i: *data)
        if (i.getId() == id) {
            i.setLocation(location);
            return;
        }
}

void ElectricScooterRepository::updateMileage(float mileage, const string &id) {
    for (auto &i: *data)
        if (i.getId() == id) {
            i.setMileage(mileage);
            return;
        }
}

void ElectricScooterRepository::updateModel(const string &model, const string &id) {
    for (auto &i: *data)
        if (i.getId() == id) {
            i.setModel(model);
            return;
        }
}

vector<ElectricScooter> ElectricScooterRepository::getAll() {
    return *data;
}

unique_ptr<vector<ElectricScooter>> ElectricScooterRepository::getAllAsPointer() {
    return std::make_unique<vector<ElectricScooter>>(*data);
}

void ElectricScooterRepository::deleteAllData() {
    data = std::make_shared<vector<ElectricScooter>>();
}

void ElectricScooterRepository::reserveScooter(const string &id) {
    for (auto &i: *data)
        if (i.getId() == id) {
            if (i.getCondition() != "Parked")
                throw exception();
            i.setCondition("Reserved");
            return;
        }
}

void ElectricScooterRepository::useScooter(const string &id) {
    for (auto &i: *data)
        if (i.getId() == id) {
            if (i.getCondition() != "Parked")
                throw exception();
            i.setCondition("In use");
            return;
        }
}