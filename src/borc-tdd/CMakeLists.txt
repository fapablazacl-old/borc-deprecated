
set (target "borc-tdd")
set (sources 
    "MainTest.cpp"
    "ProjectModelTest.cpp"
)

include_directories("../borc-core/")

source_group(\\ FILES ${sources})

add_executable(${target} ${sources})

target_link_libraries(${target} borc-core)
