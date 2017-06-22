
set (target "borc-tdd")
set (sources "TestSomething.cpp")

include_directories("../dep/unittest-cpp/")
include_directories("../src/borc/")

add_executable(${target} ${sources})

target_link_libraries(${target} UnitTest++ borc-core)
