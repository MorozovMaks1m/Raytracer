cmake_minimum_required(VERSION 3.16)

# set the project name
project(Raytracer)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(utils)

add_executable(Raytracer main.cpp)
target_link_libraries(Raytracer PUBLIC Utils)