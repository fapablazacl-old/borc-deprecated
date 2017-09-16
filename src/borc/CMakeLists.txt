
# setup borc-core
include_directories("../borc-core/")

# setup boost
set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_PROGRAM_OPTIONS_DYN_LINK)

set (target "borc")
set (sources 
    "Program.cpp"
    "borc/Task.hpp"
    "borc/Task.cpp"
    "borc/CommandTask.hpp"
    "borc/CommandTask.cpp"
    "borc/TaskPerformer.hpp"
    "borc/TaskPerformer.cpp"
    "borc/SerialTaskPerformer.hpp"
    "borc/SerialTaskPerformer.cpp"
    
	"borc/Target.hpp"
    "borc/Target.cpp"
    "borc/Project.hpp"
    "borc/Project.cpp"
    #"borc/ProjectParser.hpp"
    #"borc/ProjectParser.cpp"

    # C++ language support
    "borc/cpp/CppProject.hpp"
    "borc/cpp/CppProject.cpp"
)

find_package(Boost 1.45.0 REQUIRED COMPONENTS
    program_options
    filesystem
)

include_directories(${Boost_INCLUDE_DIRS})

source_group(\\ FILES ${sources})

add_executable (${target} ${sources})

target_link_libraries (
    ${target} 
    ${Boost_LIBRARIES} 
    #borc-core
    #yaml-cpp
)

install(TARGETS ${target} DESTINATION "bin")
