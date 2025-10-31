add_library(Shapes 
    color.cpp
    hittable_list.cpp
    sphere.cpp)

target_include_directories(Shapes PRIVATE ${CMAKE_SOURCE_DIR})