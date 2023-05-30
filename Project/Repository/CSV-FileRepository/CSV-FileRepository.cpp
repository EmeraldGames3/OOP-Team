#include "CSV-FileRepository.h"
#include <iostream>
#include <fstream>

using Repository::CSVFileRepository, std::ifstream, std::ofstream;

template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>
CSVFileRepository<StoredObject>::CSVFileRepository(const string &file) {
    this->fileName = file;
    ifstream fin(this->fileName);

    if (!fin.is_open()) {
        throw std::invalid_argument("File cannot be found");
    }

    string line;
    std::getline(fin, line); //Read the line with the format

    StoredObject temp; // I have to use this because c++ does not let me override static functions
    while (std::getline(fin, line)) {
        this->data.push_back(temp.convertFromString(line));
    }

    fin.close();
}

template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>void CSVFileRepository<StoredObject>::writeToFile() {
    ofstream file(this->fileName);

    StoredObject temp; // I have to use this because c++ does not let me override static functions
    file << temp.getAttributes() << '\n';
    for (auto &it: this->data) {
        file << it->toString() << '\n';
    }

    file.close();
}

template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>vector<StoredObject>
CSVFileRepository<StoredObject>::findAll() const {
    vector<StoredObject> returnVector{};

    for (const auto &ptr: this->data) {
        auto *obj = dynamic_cast<StoredObject *>(ptr.get());
        if (obj) {
            returnVector.push_back(*obj);
        }
    }

    return returnVector;
}

template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>bool
CSVFileRepository<StoredObject>::remove(const StoredObject &storedObject) {
    for (int i = 0; i < this->data.size(); i++) {
        if (this->data[i]->getId() == storedObject.getId()) {
            this->data.erase(this->data.begin() + i);
            writeToFile();
            return true;
        }
    }
    writeToFile();
    return false;
}

template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>bool
CSVFileRepository<StoredObject>::update(const StoredObject &oldObject, const StoredObject &newObject) {
    for (auto &it: this->data) {
        if (it->getId() == oldObject.getId()) {
            it = make_unique<StoredObject>(newObject);
            writeToFile();
            return true;
        }
    }
    writeToFile();
    return false;
}

template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>void
CSVFileRepository<StoredObject>::create(const StoredObject &storedObject) {
    this->data.push_back(make_unique<StoredObject>(storedObject));
    writeToFile();
}

//Instantiate the templated class to allow the compiler to generate the necessary code
template class Repository::CSVFileRepository<ElectricScooter>;
template class Repository::CSVFileRepository<User>;
template class Repository::CSVFileRepository<Manager>;
template class Repository::CSVFileRepository<Client>;