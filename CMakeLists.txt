
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(borc)

set (CMAKE_CXX_STANDARD 17)

# Catch testing framework
include_directories("dep/Catch/include")

# borc core
add_subdirectory("src/borc-core")

# borc command line utility
add_subdirectory("src/borc")

# unit testing
add_subdirectory("src/borc-tdd")
enable_testing()

add_test(BorcTest "${CMAKE_CURRENT_BINARY_DIR}/src/borc-tdd/borc-tdd")
