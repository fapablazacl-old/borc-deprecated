
set (target "borc")
set (sources "Program.cpp")

add_executable(${target} ${sources})

target_link_libraries(${target} borc-core)
