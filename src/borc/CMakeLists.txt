
set (target "borc")
set (sources "Program.cpp")

find_package(Boost 1.45.0 REQUIRED COMPONENTS
    program_options
)

include_directories(${Boost_INCLUDE_DIRS})

add_executable (${target} ${sources})

target_link_libraries (
    ${target} 
    ${Boost_LIBRARIES} 
    borc-core
)

install(TARGETS ${target} DESTINATION "bin")
