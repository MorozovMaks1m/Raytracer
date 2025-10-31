cmake_minimum_required(VERSION 3.16)
project(Raytracer LANGUAGES CXX)

# === General Settings ===
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Subdirectories ===
add_subdirectory(utils)
add_subdirectory(shapes)
add_subdirectory(materials)

# === Executable ===
add_executable(Raytracer main.cpp)
target_link_libraries(Raytracer PUBLIC Utils Shapes Materials)
target_include_directories(Raytracer PRIVATE ${CMAKE_SOURCE_DIR})

add_custom_target(generate-image
    COMMAND Raytracer > pic.ppm
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Generating image pic.ppm"
)

# === Collect all source files (excluding build/out dirs) ===
file(GLOB_RECURSE TMP_SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.h"
)

set(ALL_SOURCE_FILES "")
foreach(f ${TMP_SOURCE_FILES})
    if(NOT f MATCHES ".*/out/.*" AND NOT f MATCHES ".*/build/.*")
        list(APPEND ALL_SOURCE_FILES ${f})
    endif()
endforeach()

# === clang-format target ===
find_program(CLANG_FORMAT_EXECUTABLE NAMES clang-format)
if(CLANG_FORMAT_EXECUTABLE)
    add_custom_target(format
        COMMAND ${CLANG_FORMAT_EXECUTABLE}
            -i
            --verbose
            -style=file
            ${ALL_SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-format on all source files"
    )
else()
    message(WARNING "clang-format not found! Please install it to enable 'format' target.")
endif()

# === clang-tidy target ===
find_program(CLANG_TIDY_EXE NAMES clang-tidy)

if(CLANG_TIDY_EXE)
    message(STATUS "Found clang-tidy: ${CLANG_TIDY_EXE}")

    # Ask macOS for the SDK path (only runs on Apple systems)
    if(APPLE)
        execute_process(
            COMMAND xcrun --show-sdk-path
            OUTPUT_VARIABLE OSX_SDK_PATH
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )

        # Use libc++ (Apple’s C++ standard library)
        set(EXTRA_TIDY_ARGS
            --extra-arg=-isysroot
            --extra-arg=${OSX_SDK_PATH}
            --extra-arg=-stdlib=libc++
            --extra-arg=-std=c++23
        )
    else()
        set(EXTRA_TIDY_ARGS
            --extra-arg=-std=c++23
        )
    endif()

    # Manual tidy target (runs clang-tidy on all sources)
    add_custom_target(tidy-fix
        COMMAND ${CLANG_TIDY_EXE}
            --fix
            --fix-errors
            -p ${CMAKE_BINARY_DIR}
            ${ALL_SOURCE_FILES}
            ${EXTRA_TIDY_ARGS}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-tidy and applying automatic fixes"
    )
else()
    message(WARNING "clang-tidy not found! Please install it to enable 'tidy-fix' target.")
endif()
