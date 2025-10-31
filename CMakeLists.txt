cmake_minimum_required(VERSION 3.16)

# set the project name
project(Raytracer)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(utils)
add_subdirectory(shapes)

add_executable(Raytracer main.cpp)
target_link_libraries(Raytracer PUBLIC Utils Shapes)

set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "include-what-you-use;-Xiwyu;--check_also=*.h")

target_include_directories(Raytracer PRIVATE ${CMAKE_SOURCE_DIR})