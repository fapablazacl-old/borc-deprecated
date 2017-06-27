
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(borc)

set (CMAKE_CXX_STANDARD 14)

# UnitTest++
add_subdirectory("dep/unittest-cpp")

# TinyXML-2
add_subdirectory("dep/tinyxml2")

# borc core
add_subdirectory("src/borc-core")

# borc command line utility
add_subdirectory("src/borc")

# unit testing
add_subdirectory("src/borc-tdd")
