cmake_minimum_required(VERSION 3.25)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project main.cpp Repository/ClientRepository.cpp Domain/User/Client.cpp Domain/ElectricScooter/ElectricScooter.cpp Controller/ElectricScooterController.cpp Repository/ElectricScooterRepository.cpp Domain/User/Manager.cpp Repository/ManagerRepository.cpp UI/UserInterface.cpp Domain/User/User.cpp Controller/UserController.cpp Repository/UserRepository.cpp Domain/Date/Date.cpp Controller/Controller.h Repository/Repository.h Domain/Domain.h UI/UI.h)
