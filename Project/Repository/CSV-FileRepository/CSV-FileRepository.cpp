#include "CSV-FileRepository.h"
#include <iostream>
#include <fstream>

using Repository::CSVFileRepository, std::ifstream, std::ofstream;

template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>
CSVFileRepository<StoredObject>::CSVFileRepository(string file) : fileName{std::move(file)} {
    ifstream fin(fileName);

    if(!fin.is_open()){
        throw std::invalid_argument("File cannot be found");
    }

    string line;
    std::getline(fin, line); //Read the line with the format

    StoredObject temp; // I have to use this because c++ does not let me override static functions
    while (std::getline(fin, line)){
        this->data.push_back(temp.convertFromString(line));
    }

    fin.close();
}

template<typename StoredObject>
requires IsSubclassOfObjectWithID<StoredObject>void CSVFileRepository<StoredObject>::writeToFile() {
    ofstream file(fileName);

    StoredObject temp; // I have to use this because c++ does not let me override static functions
    file << temp.getAttributes() << '\n';
    for(auto &it : this->data){
        file << it.toString << '\n';
    }

    file.close();
}