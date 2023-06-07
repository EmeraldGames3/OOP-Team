set(CMAKE_AUTOMOC ON)
cmake_minimum_required(VERSION 3.25)
project(Project)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "/home/bogdan/Qt/5.15.2/gcc_64/")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
file(GLOB_RECURSE SOURCE_FILES "Tests/*.cpp" "Repository/*.cpp" "Domain/*.cpp" "Controller/*.cpp" "UI/*.cpp")
add_executable(Project main.cpp ${SOURCE_FILES} UI/MainWindow/MainWindow.cpp UI/MainWindow/MainWindow.h UI/LoginPage/LoginPage.cpp UI/LoginPage/LoginPage.h UI/ManagerLabel/ManagerLabel.cpp UI/ManagerLabel/ManagerLabel.h UI/ClientLabel/ClientLabel.cpp UI/ClientLabel/ClientLabel.h)

target_link_libraries(Project Qt5::Widgets)