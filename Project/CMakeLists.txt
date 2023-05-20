cmake_minimum_required(VERSION 3.25)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project main.cpp Tests/TestRepository/TestRepository.cpp Tests/TestAll.cpp Tests/TestController/TestController.cpp Tests/TestDomain/TestDate/TestDate.cpp Tests/TestDomain/TestElectricScooter/TestElectricScooter.cpp Tests/TestDomain/TestDomain.cpp Tests/TestDomain/TestUser/TestUser.cpp Repository/CSV-FileRepository/CSV-FileRepository.cpp Repository/CSV-FileRepository/CSV-FileRepository.h Domain/User/User/User.cpp Domain/User/Manager/Manager.cpp Domain/User/Client/Client.cpp Domain/ElectricScooter/ElectricScooter.cpp Domain/Date/Date.cpp)