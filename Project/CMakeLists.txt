cmake_minimum_required(VERSION 3.25)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project main.cpp Repository/ClientRepository.cpp Domain/User/Client/Client.cpp Domain/ElectricScooter/ElectricScooter.cpp Controller/ElectricScooterController/ElectricScooterController.cpp Repository/ElectricScooterRepository.cpp Domain/User/Manager/Manager.cpp Repository/ManagerRepository.cpp UI/UserInterface.cpp Domain/User/User/User.cpp Controller/UserController/UserController.cpp Repository/UserRepository.cpp Domain/Date/Date.cpp Controller/Controller.h Repository/Repository.h Domain/Domain.h UI/UI.h Tests/TestAll.cpp Tests/TestAll.h Tests/TestDomain/TestDate/TestDate.cpp Tests/TestDomain/TestDomain.cpp Tests/TestDomain/TestDomain.h Tests/TestDomain/TestUser/TestUser.cpp Tests/TestDomain/TestUser/TestUser.h Tests/TestDomain/TestElectricScooter/TestElectricScooter.cpp Tests/TestDomain/TestElectricScooter/TestElectricScooter.h)
