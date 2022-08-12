# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(main)

# Include lib conan test
if(TEST)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()

# Options
set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES
    source/main.cpp
    source/ip_base.cpp
    include/ip_base.h
)

# Source tests files
set(TEST_SOURCES
    test/source/test_ip_base.cpp
    source/ip_base.cpp
    include/ip_base.h
)

# Include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

if(TEST)
    # Compiling target for tests
    add_executable(${PROJECT_NAME}_tests ${TEST_SOURCES})

    # Link target with gtest
    target_link_libraries(${PROJECT_NAME}_tests ${CONAN_LIBS})
endif()