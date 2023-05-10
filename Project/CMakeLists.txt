cmake_minimum_required(VERSION 3.25)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project main.cpp Controller/Controller.h Domain/Domain.h Repository/Repository.h UI/UI.h UI/UserInterafce.cpp UI/UserInterafce.h Repository/ElectricscooterRepository.cpp Repository/ElectricscooterRepository.h Domain/User/User.cpp Domain/User/User.h Domain/ElectricScooter/EclectricScooter.cpp Domain/ElectricScooter/EclectricScooter.h Domain/User/Manager.cpp Domain/User/Manager.h)
