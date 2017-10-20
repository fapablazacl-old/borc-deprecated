
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(borc)

set (CMAKE_CXX_STANDARD 17)

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
