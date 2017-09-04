
# setup boost
set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_PROGRAM_OPTIONS_DYN_LINK)

set (target "borc")
set (sources "Program.cpp")

find_package(Boost 1.45.0 REQUIRED COMPONENTS
    program_options
    filesystem
)

include_directories(${Boost_INCLUDE_DIRS})

# setup yaml-cpp

# setup target
set (target "borc-core")

set (sources 
    "borc/Task.hpp"
    "borc/Task.cpp"
    "borc/CommandTask.hpp"
    "borc/CommandTask.cpp"
    "borc/TaskPerformer.hpp"
    "borc/TaskPerformer.cpp"
    "borc/SerialTaskPerformer.hpp"
    "borc/SerialTaskPerformer.cpp"
    
    "borc/Project.hpp"
    "borc/Project.cpp"
    "borc/ProjectParser.hpp"
    "borc/ProjectParser.cpp"

	"borc/CppTarget.hpp"
    "borc/CppTarget.cpp"
    "borc/CppProject.hpp"
    "borc/CppProject.cpp"
    "borc/CppProjectParser.hpp"
    "borc/CppProjectParser.cpp"
)

source_group("\\borc" FILES ${sources})

add_library(${target} ${sources})

target_link_libraries (
    ${target} 
    ${Boost_LIBRARIES} 
    yaml-cpp
)
