
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(borc)

set (CMAKE_CXX_STANDARD 14)

# UnitTest++
add_subdirectory("dep/unittest-cpp")

# borc core
add_subdirectory("src/borc")

# unit testing
include_directories("dep/unittest-cpp/")
add_subdirectory("src/borc-tdd")
