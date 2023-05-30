cmake_minimum_required(VERSION 3.25)
project(Project)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "/home/bogdan/Qt/5.15.2/gcc_64/")
find_package(Qt5Widgets REQUIRED)
file(GLOB_RECURSE SOURCE_FILES "Tests/*.cpp" "Repository/*.cpp" "Domain/*.cpp" "Controller/*.cpp" "UI/*.cpp")
add_executable(Project main.cpp ${SOURCE_FILES})

target_link_libraries(Project Qt5::Widgets)