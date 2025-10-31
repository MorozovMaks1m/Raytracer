add_library(Materials 
    dielectric.cpp
    lambertian.cpp
    metal.cpp)

target_include_directories(Materials PRIVATE ${CMAKE_SOURCE_DIR})