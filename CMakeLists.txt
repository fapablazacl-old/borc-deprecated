
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(borc)

set (CMAKE_CXX_STANDARD 17)

set (BORC_VERSION_MAJOR "0")
set (BORC_VERSION_MINOR"0")
set (BORC_VERSION_REVISION "0")

add_definitions("-DCMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")

add_definitions("-DBORC_VERSION_MAJOR=${BORC_VERSION_MAJOR}")
add_definitions("-DBORC_VERSION_MINOR=${BORC_VERSION_MINOR}")
add_definitions("-DBORC_VERSION_REVISION=${BORC_VERSION_REVISION}")

# Catch testing framework
include_directories("dep/Catch/include")

# yaml-cpp library
#add_subdirectory("dep/yaml-cpp")
#include_directories("dep/yaml-cpp/include")

# fmt testing format library
include_directories("dep/fmt/")
add_subdirectory("dep/fmt/")

# borc core
include_directories("src/borc-core")
add_subdirectory("src/borc-core")

# borc command line utility
include_directories("src/borc")
add_subdirectory("src/borc")

# unit testing
add_subdirectory("src/borc-test")

# test-driven development
add_subdirectory("src/borc-tdd")
