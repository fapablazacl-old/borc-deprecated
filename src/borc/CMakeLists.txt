
set (target "borc")
set (sources "Program.cpp")

find_package(Boost 1.45.0 REQUIRED COMPONENTS
    program_options
    filesystem
)

include_directories(${Boost_INCLUDE_DIRS})

add_executable (${target} ${sources})

target_link_libraries (
    ${target} 
    ${Boost_LIBRARIES} 
    borc-core
    yaml-cpp
)

install(TARGETS ${target} DESTINATION "bin")
